from z3 import *

x = BitVec("x",32) # eax
y = BitVec("y",32)
z = BitVec("z",32)

y = (x+0x11) * (x+0xb) # ecx
z = y >> 8 # edx


solve(BV2Int(x)<0xffff,(( ((z^y) >> 0x10) ^ z) ^ y) == 0x4496ff7)
print(hex(int(input())))

# 188d1f2f 0x4f47
# 13cd5b60 0x4744
# 1bd6047f 0x5450
# 4496ff7  0x2121
# 4496ff7  0x2121
# 4496ff7  0x2121

# 0x474f44475054212121212121

# >>> from Crypto.Util.number import long_to_bytes
# >>> long_to_bytes(0x474f44475054212121212121)
# b'GODGPT!!!!!!'
