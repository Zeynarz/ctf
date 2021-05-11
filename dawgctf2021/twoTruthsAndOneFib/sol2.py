from pwn import *
from math import *
from multiprocessing import *
def fib1(n,wrong):
    n = int(n)
    equated = 5*(n**2)
    plus = str(equated + 4)
    minus = str(equated - 4)
    plusCheck = False
    minusCheck = False
    #checking if it is a perfect square
    if plus[-1] == "2" or plus[-1] == "3" or plus[-1] == "7" or plus[-1] == "8":
        pass
    else:
        plusCheck = True
    if minus[-1] == "2" or minus[-1] == "3" or minus[-1] == "7" or minus[-1] == "8":
        pass
    else:   
        minusCheck = True
    
    if not minusCheck and not plusCheck:
        wrong[0] = 1
        try:
            p2.terminate()
            p3.terminate()
        except:
            pass
        return

    #checking digitalroot(Eliminating impossible ones)
    if plusCheck:
        while len(plus) != 1:
            newnum = 0
            for num in plus:
                newnum += int(num)
            plus = str(newnum)
    
        if plus[-1] != "0" and plus[-1] != "1" and plus[-1] != "4" and plus[-1] != "7":
            plusCheck = False

    if minusCheck:
        while len(minus) != 1:
            newnum = 0
            for num in minus:
                newnum += int(num)
            minus = str(newnum)
        
        if minus[-1] != "0" and minus[-1] != "1" and minus[-1] != "4" and minus[-1] != "7":
            minusCheck = False    
            
    if not minusCheck and not plusCheck:
        wrong[0] = 1
        try:
            p2.terminate()
            p3.terminate()
        except:
            pass
        return

    #checking if others are wrong
    if wrong[1] and wrong[2]:
        io.sendline(str(n))
        try:
            p2.terminate()
            p3.terminate()
        except:
            pass
        return

    #final check
    if plusCheck:
        integer = sqrt(equated + 4)
        checkNum = integer - int(integer)
        if checkNum > 0.99 or checkNum < 0.0001:
            io.sendline(str(n))
            try:
                p2.terminate()
                p3.terminate()
            except:
                pass
            return

    if minusCheck:
        integer = sqrt(equated - 4)
        checkNum = integer - int(integer)
        if checkNum > 0.99 or checkNum < 0.0001:
            io.sendline(str(n))
            try:
                p2.terminate()
                p3.terminate()
            except:
                pass
            return

    wrong[0] = 1
    return

def fib2(n,wrong):
    n = int(n)
    equated = 5*(n**2)
    plus = str(equated + 4)
    minus = str(equated - 4)
    plusCheck = False
    minusCheck = False
    #checking if it is a perfect square
    if plus[-1] == "2" or plus[-1] == "3" or plus[-1] == "7" or plus[-1] == "8":
        pass
    else:
        plusCheck = True
    if minus[-1] == "2" or minus[-1] == "3" or minus[-1] == "7" or minus[-1] == "8":
        pass
    else:   
        minusCheck = True
    
    if not minusCheck and not plusCheck:
        wrong[1] = 1
        try:
            p1.terminate()
            p3.terminate()
        except:
            pass
        return

    #checking digitalroot(Eliminating impossible ones)
    if plusCheck:
        while len(plus) != 1:
            newnum = 0
            for num in plus:
                newnum += int(num)
            plus = str(newnum)
    
        if plus[-1] != "0" and plus[-1] != "1" and plus[-1] != "4" and plus[-1] != "7":
            plusCheck = False

    if minusCheck:
        while len(minus) != 1:
            newnum = 0
            for num in minus:
                newnum += int(num)
            minus = str(newnum)
        
        if minus[-1] != "0" and minus[-1] != "1" and minus[-1] != "4" and minus[-1] != "7":
            minusCheck = False    
            
    if not minusCheck and not plusCheck:
        wrong[1] = 1
        try:
            p1.terminate()
            p3.terminate()
        except:
            pass
        return

    #checking if others are wrong
    if wrong[0] and wrong[2]:
        io.sendline(str(n))
        try:
            p1.terminate()
            p3.terminate()
        except:
            pass
        return

    #final check
    if plusCheck:
        integer = sqrt(equated + 4)
        checkNum = integer - int(integer)
        if checkNum > 0.99 or checkNum < 0.0001:
            io.sendline(str(n))
            try:
                p1.terminate()
                p3.terminate()
            except:
                pass
            return

    if minusCheck:
        integer = sqrt(equated - 4)
        checkNum = integer - int(integer)
        if checkNum > 0.99 or checkNum < 0.0001:
            io.sendline(str(n))
            try:
                p1.terminate()
                p3.terminate()
            except:
                pass
            return

    wrong[1] = 1
    return

def fib3(n,wrong):
    n = int(n)
    equated = 5*(n**2)
    plus = str(equated + 4)
    minus = str(equated - 4)
    plusCheck = False
    minusCheck = False
    #checking if it is a perfect square
    if plus[-1] == "2" or plus[-1] == "3" or plus[-1] == "7" or plus[-1] == "8":
        pass
    else:
        plusCheck = True
    if minus[-1] == "2" or minus[-1] == "3" or minus[-1] == "7" or minus[-1] == "8":
        pass
    else:   
        minusCheck = True
    
    if not minusCheck and not plusCheck:
        wrong[2] = 1
        try:
            p1.terminate()
            p2.terminate()
        except:
            pass
        return

    #checking digitalroot(Eliminating impossible ones)
    if plusCheck:
        while len(plus) != 1:
            newnum = 0
            for num in plus:
                newnum += int(num)
            plus = str(newnum)
    
        if plus[-1] != "0" and plus[-1] != "1" and plus[-1] != "4" and plus[-1] != "7":
            plusCheck = False

    if minusCheck:
        while len(minus) != 1:
            newnum = 0
            for num in minus:
                newnum += int(num)
            minus = str(newnum)
        
        if minus[-1] != "0" and minus[-1] != "1" and minus[-1] != "4" and minus[-1] != "7":
            minusCheck = False    
            
    if not minusCheck and not plusCheck:
        wrong[2] = 1
        try:
            p1.terminate()
            p2.terminate()
        except:
            pass
        return

    #checking if others are wrong
    if wrong[0] and wrong[1]:
        io.sendline(str(n))
        try:
            p1.terminate()
            p2.terminate()
        except:
            pass
        return

    #final check
    if plusCheck:
        integer = sqrt(equated + 4)
        checkNum = integer - int(integer)
        if checkNum > 0.99 or checkNum < 0.0001:
            io.sendline(str(n))
            try:
                p1.terminate()
                p2.terminate()
            except:
                pass
            return

    if minusCheck:
        integer = sqrt(equated - 4)
        checkNum = integer - int(integer)
        if checkNum > 0.99 or checkNum < 0.0001:
            io.sendline(str(n))
            try:
                p1.terminate()
                p2.terminate()
            except:
                pass
            return

    wrong[2] = 1
    return

io = remote("umbccd.io",6000)
wrong = Array('i',3)
while True:
    io.recvuntil("[")
    numbers = io.recvuntil("]")[:-1].decode()
    nlist = numbers.split(", ")
    wrong[0] = 0
    wrong[1] = 0
    wrong[2] = 0
    p1 = Process(target=fib1,args=(nlist[0],wrong))
    p2 = Process(target=fib2,args=(nlist[1],wrong))
    p3 = Process(target=fib3,args=(nlist[2],wrong))
    p1.start()
    p2.start()
    p3.start()
    p1.join()
    p2.join()
    p3.join()
    print("done")
