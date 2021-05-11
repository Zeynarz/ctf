from pwn import *
from math import *
def fib(n):
    equated = 5*(n**2)
    integer1 = int(sqrt(equated + 4))
    integer2 = int(sqrt(equated - 4))
    return (integer1 * integer1 == equated + 4) or (integer2 * integer2 == equated - 4)

io = remote("umbccd.io",6000)
io.recvuntil("[")
numbers = (io.recvuntil("]")[:-2]).decode()
while True:
    nlist = numbers.split(", ")
    for n in nlist:
        num = int(n)
        if fib(num):
            io.sendline(n)
            break
    print(nlist)
    io.recvuntil(b"[")
    numbers = io.recvuntil("]")[:-1].decode()
