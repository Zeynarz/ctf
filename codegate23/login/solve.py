# https://www.skullsecurity.org/2012/everything-you-need-to-know-about-hash-length-extension-attacks
# https://en.wikipedia.org/wiki/Length_extension_attack
# https://justcryptography.com/length-extension-attack/#:~:text=The%20length%20extension%20attack%20exploits,the%20end%20of%20the%20execution.

from pwn import *
#io = process(["python3","chall.py"])
io = remote("13.124.163.225",8282)

# the length field of md5 hash uses little-endian, whereas sha1 uses big-endian 
md5Padding  = b"\x80".ljust(0x40-20-8,b"\x00") 
md5Padding += p64(20*8)

sha1Padding  = b"\x80".ljust(0x40-20-8,b"\x00")
sha1Padding += b"\x00" * 7 + b"\xa0"

md5Padding  = bytes.hex(md5Padding)
sha1Padding = bytes.hex(sha1Padding)

def hashExtender(ogSignature,append,hashFormat):
    # this finds the hash of password+padding+ownMessage
    # NOT the hash of password+ownMessage
    a = process(["./hash_extender","-s",ogSignature,"-a",append,"-f",hashFormat,"-l","20",'--data='])
    a.recvline()
    a.recvline()
    return a.recvline()[15:-1]

io.sendlineafter("**","1")

# get creds
io.recvuntil("USER_ID = ")
userId = io.recv(8)

io.recvuntil("USER_PW = ")
userPw = io.recv(8)

io.recvuntil("md5(id_key) = ")
idKeyMd5 = io.recv(32)

io.recvuntil("sha1(pw_key) = ")
pwKeySha1 = io.recv(40)

# login
io.sendline("2")

creds = md5Padding + bytes.hex(userId) + ":" + sha1Padding + bytes.hex(userPw)
io.sendlineafter("70617373",creds)

# calculate and send hash
md5Hash = hashExtender(idKeyMd5,userId,"md5")
sha1Hash = hashExtender(pwKeySha1,userPw + md5Hash,"sha1")

io.sendline(sha1Hash)
io.interactive()
