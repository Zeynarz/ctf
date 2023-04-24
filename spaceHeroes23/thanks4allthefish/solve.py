from setproctitle import *
from pwn import *

setproctitle("tidbits")

io = process("./thanks4allthefish")

io.interactive()
