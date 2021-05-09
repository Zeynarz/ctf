intList = []
approved1 = []
approved2 = []
def algorithm(n):
    numVar = 3
    while(n/2 > numVar):
        if n % numVar == 0:
            return False
        numVar += 2
    return True 

def switchOverInt(n):
    sn = str(n)
    sn2 = sn[2] + sn[0] + sn[1]
    return int(sn2)


for i in range(101,int(0x1fd + 1)):
    if i % 2 != 0:
        intList.append(i)

for i in intList:
    if algorithm(i):
        approved1.append(i)

for i in approved1:
    newI = switchOverInt(i)
    newI2 = switchOverInt(newI)
    if newI > 100 and newI2 > 100:
        if algorithm(newI) and algorithm(newI2):
            approved2.append(i)

for a in approved2:
    for b in approved2:
        for c in approved2:
            if a + b + c == 0x1fd and a != b and a != c and b != c:
                print(a,b,c)


