ans = "\"_9~Jb0!=A`G!06qfc8\'_20uf6`2%7"
flag = ""
for i in ans:
    c = ord(i)
    #function 2
    if c <= 32 or c == 127:
        c = c
    elif c <= 80:
        c += 47
    else:
        c = c - 94 + 47
    #function 1 p2
    if c <= 96 or c >= 123:
        c = c
    elif c <= 109:
        c += 13
    else:
        c = c - 26 + 13
    #function 1 p1
    if c <= 64 or c >= 91:
        c = c
    elif c <= 77:
        c += 13
    else:
        c = c - 26 + 13
    flag += chr(c)

print(flag)

