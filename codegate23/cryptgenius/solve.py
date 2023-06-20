from pwn import *
import base64
io = remote("13.124.113.252",12345)
#io = process(["python3","cryptGenius.py"])

target = b"6230ee81ac9d7785a16c75b93a89de9cbb9cbb2ddabaaadd035378c36a44eeacb371322575b467a4a3382e3085da281731557dadd5210f21b75e1e9b7e426eb7"

finalStr = b""

n = 8
for i in range(n):
    io.sendlineafter("your behavior >","1")
    io.sendlineafter("Do you want to experiment? >",target[i*16:i*16+16]) # an AES ECB block is 16 bytes
    io.recvuntil("b'")
    b64Str = io.recvuntil("'")[:-1].decode()
    finalStr += base64.b64decode(b64Str)
    if i != n-1:
        finalStr = finalStr[:-16]

finalStr = base64.b64encode(finalStr)
io.sendlineafter("your behavior >","2")
io.sendlineafter("Did you already solve the trick? >",finalStr)


# used this to figure out the finalStr += ... [:-16]
"""
target = "AAAABBBBCCCCDDDD1111222233334444"
print(finalStr)
print(base64.b64decode("8m85rQ3LhAN8d3gg0neOzAiaEdsYZcOOYAda+36D8j8FFb4dmvtMVKIDkJc/WCjY"))
"""

io.interactive()
