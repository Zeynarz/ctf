from Crypto.Util.number import long_to_bytes
flag = ""
for char in "od_pbw1gu":
    flag += chr(ord(char)+4)

flag += long_to_bytes(0x5F31735F6E30745F74).decode()

for char in "d/[h-i-py":
    flag += chr(ord(char)+4)

print(flag)
