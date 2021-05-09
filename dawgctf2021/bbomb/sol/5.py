intList = []
approved = []
def algorithm(n):
    numVar = 3
    while(n/2 > numVar):
        if n % numVar == 0:
            return False
        numVar += 2
    return True 

for i in range(2010,int(8084 + 1)):
    if i % 2 != 0:
        intList.append(i)

for i in intList:
    if algorithm(i):
        approved.append(i)

for a in approved:
    for b in approved:
        for c in approved:
            for d in approved:
                if a + b + c + d == 8084:
                    print(a,b,c,d)


