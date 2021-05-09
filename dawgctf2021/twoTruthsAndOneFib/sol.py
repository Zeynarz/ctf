from pwn import *
from math import *
def isPerfectSquare(n):
    integer = int(sqrt(n))
    return ((integer * integer) == n)

def fib(n):
    equated = 5*(n**2)
    return (isPerfectSquare(equated + 4) or isPerfectSquare(equated - 4))

io = remote("umbccd.io",6000)
while True:
    io.recvuntil("[")
    numbers = (io.recvuntil("]")[:-2]).decode()
    nlist = numbers.split(", ")
    for n in nlist:
        num = int(n)
        if fib(num):
            io.sendline(n)
            break

