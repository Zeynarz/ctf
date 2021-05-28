import socket
import struct

HOST = "127.0.0.1"
PORT = 2997

s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect((HOST,PORT))
ans = 0
for i in range(4):
        n = struct.unpack("I",s.recv(4))[0]
        ans += n
print ans
s.send(struct.pack("I",ans & 0xffffffff))
print(s.recv(1024))
