from pwn import *
import base64,codecs,string
io = remote("pwn-2021.duc.tf",31905)

io.sendline("a") #Start the quiz 

#Q1
io.sendlineafter("1+1=?","2")

#Q2
io.recvuntil("Decode this hex string and provide me the original number (base 10): ")
io.sendline(str(int(io.recv(4),16)))

#Q3
io.recvuntil("Decode this hex string and provide me the original ASCII letter: ")
hexString = "0x" + io.recv(2).decode()
io.sendline(chr(int(hexString,16)))

#Q4 (ans for this question doesnt work 100% of the time)
io.recvuntil("Decode this URL encoded string and provide me the original ASCII symbols: ")
urlString = io.recv(9).decode()
hexString = [urlString[1:3],urlString[4:6],urlString[7:]]
ans = ""
for i in hexString:
    ans += chr(int("0x" + i,16))

io.sendline(ans)

#Q5
io.recvuntil("Decode this base64 string and provide me the plaintext: ")
base64Str = io.recv()[:-1].decode()

b64Bytes = base64Str.encode("ascii")
decodedBytes = base64.b64decode(b64Bytes)
decoded = decodedBytes.decode("ascii")

io.sendline(decoded)

#Q6
io.recvuntil("Encode this plaintext string and provide me the Base64: ")
toEncode = io.recv()[:-1].decode()

toEncodeBytes = toEncode.encode("ascii")
b64Bytes = base64.b64encode(toEncodeBytes)
encoded = b64Bytes.decode("ascii")

io.sendline(encoded)

#Q7
io.recvuntil("Decode this rot13 string and provide me the plaintext: ")
toDecode = io.recv()[:-1].decode()

rot13 = "NOPQRSTUVWXYZnopqrstuvwxyzABCDEFGHIJKLMabcdefghijklm"
alphabet = "ABCDEFGHIJKLMabcdefghijklmNOPQRSTUVWXYZnopqrstuvwxyz"

encodeRot = {}
decodeRot = {}

for index,i in enumerate(rot13):
    encodeRot[alphabet[index]] = i
    decodeRot[i] = alphabet[index]

ans = ""
for i in toDecode:
    if i == "_":
        ans += "_"
        continue
    ans += decodeRot[i]
    
io.sendline(ans)

#Q8
io.recvuntil("Encode this plaintext string and provide me the ROT13 equilavent: ")
toEncode = io.recv()[:-1].decode()

ans = ""
for i in toEncode:
    if i == "_":
        ans += "_"
        continue 
    ans += encodeRot[i]

io.sendline(ans)

#Q9
io.recvuntil("Decode this binary string and provide me the original number (base 10): ")
binaryNum = io.recv()[:-1].decode()

io.sendline(str(int(binaryNum,2)))

#Q10
io.recvuntil("Encode this number and provide me the binary equivalent: ")
decimal = int(io.recv()[:-1].decode())

io.sendline(bin(decimal))

#Q11
io.recvuntil("Final Question, what is the best CTF competition in the universe?")
io.sendline("DUCTF")

io.interactive()

