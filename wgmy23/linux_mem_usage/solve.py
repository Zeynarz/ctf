# tried to write it in C++, but the memUsed function just didnt iterate through the child's children for some reason
# but this doesn't work cause of the time limit, so gotta go back to C++ ig
# was it a pointer issue? I didnt use current as a Process* and also didnt use new? idk. prob
# cause before, the Processes were all stored in the same memory address mcm lol

class Process:
    def __init__(self,a,b,c):
        self.pid = a
        self.ppid = b
        self.mem = c
        self.children = []
    
    def memUsed(self):
        used = self.mem
        for child in self.children:
            used += child.memUsed()

        return used


allProcess = {}
n,q = [int(a) for a in input().split()]

for i in range(n):
    a,b,c =  [int(j) for j in input().split()]
    current = Process(a,b,c)
    allProcess[a] = current

    if b != 0:
        allProcess[b].children.append(current)

for i in range(q):
    pid = int(input())
    print(allProcess[pid].memUsed())
