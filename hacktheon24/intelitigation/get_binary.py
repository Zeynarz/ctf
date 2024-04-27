from pwn import * 
from base64 import b64decode
io = remote("hto2024-nlb-fa01ec5dc40a5322.elb.ap-northeast-2.amazonaws.com",5001)
io.recvline()
io.recvline()

b64_binary = io.recvline()[:-1]
binary = b64decode(b64_binary)

with open("chall","wb") as chall_file:
    chall_file.write(binary)

