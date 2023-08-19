from Crypto.Util.number import bytes_to_long,long_to_bytes
from pwn import *
#io = process(["python3","modifiedChall.py"])
io = remote("aes.sstf.site",1337)


ct = "00"*16
ctAfterAES = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
IV = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]

listToHex = lambda iv : "".join([hex(i)[2:].rjust(2,"0") for i in iv])


for padNum in range(1,17):
    index = 16-padNum

    # prepare IV for next padding brute
    for i in range(index+1,16):
        IV[i] = ctAfterAES[i] ^ padNum 

    for IVByte in range(0x100):
        IV[index] = IVByte
        io.sendlineafter("IV(hex):",listToHex(IV))
        io.sendlineafter("CipherText(hex):",ct)

        resp = io.recvuntil(".")
        if b"Wrong CipherText" in resp:
            # got the padding right
            ctAfterAES[index] = IVByte ^ padNum
            break
           
print(ctAfterAES)
# setup IV so that pt decrypted is "CBC Magic!"
for i,char in enumerate("CBC Magic!"):
    IV[i] = ctAfterAES[i] ^ ord(char)

# turn the remaining into padding
strLen = len("CBC Magic!")  
for i in range(strLen,16):
    IV[i] = ctAfterAES[i] ^ (16 - len("CBC Magic!"))
    

io.sendlineafter("IV(hex):",listToHex(IV))
io.sendlineafter("CipherText(hex):",ct)

io.interactive()
io.close()
