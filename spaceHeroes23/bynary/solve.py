with open("transmission.txt","rb") as t:
    binary = t.read()
    binary = binary.replace(b" ",b"0")
    binary = binary.replace(b"\t",b"1")

    binary = binary.decode("utf-8").split()
    
flag = ""
for char in binary:
    flag += chr(int(char,2))

print(flag)
