import socket
import struct

HOST = "127.0.0.1"
PORT = 2998

s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect((HOST,PORT))
n = struct.unpack("I",s.recv(4))[0]
s.send(str(n))
print(s.recv(1024))
