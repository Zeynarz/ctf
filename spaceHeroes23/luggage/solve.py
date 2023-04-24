from Crypto.Util.number import *
from pwn import xor

with open("hash.txt","r") as hashFile:
    hexStr = hashFile.read()
    a = long_to_bytes(int(hexStr[:80],16))
    b = long_to_bytes(int(hexStr[80:160],16))
    c = long_to_bytes(int(hexStr[160:],16))


k1Xork2 = xor(b,c)
print(xor(a,k1Xork2))
