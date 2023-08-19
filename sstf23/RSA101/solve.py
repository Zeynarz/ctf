from Crypto.Util.number import long_to_bytes,bytes_to_long,inverse,getPrime
from pwn import *
from base64 import *

#io = process(["python3","challenge.py"])
io = remote("rsa101.sstf.site",1104)

def signNum(num):
    io.sendlineafter(">","2")
    numB64 = b64encode(long_to_bytes(num))
    io.sendlineafter("sign: ",numB64)
    
    io.recvuntil("Signed command: ")
    signature = b64decode(io.recvline()[:-1])
    return bytes_to_long(signature)

io.recvuntil("n = ")
n = int(io.recvline()[:-1],16)
e = 0x10001

m = bytes_to_long(b"cat flag")
m1 = getPrime(128) # a prime number so that gcd(m1,n) is always = 1
m2 = (m * inverse(m1,n)) % n

s1 = signNum(m1)
s2 = signNum(m2)

s = (s1*s2) % n

io.sendlineafter(">","1")
io.sendlineafter("command: ",b64encode(long_to_bytes(s)))
io.interactive()
