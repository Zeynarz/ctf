from Crypto.Util.number import long_to_bytes
from pwn import xor

msg = "RC4 is a Stream Cipher, which is very simple and fast."
msgCt = 0x634c3323bd82581d9e5bbfaaeb17212eebfc975b29e3f4452eefc08c09063308a35257f1831d9eb80a583b8e28c6e4d2028df5d53df8
flagCt = 0x624c5345afb3494cdd6394bbbf06043ddacad35d28ceed112bb4c8823e45332beb4160dca862d8a80a45649f7a96e9cb

key = xor(msg,long_to_bytes(msgCt))
print(xor(long_to_bytes(flagCt),key))
