battleshipMap = ["~"*163,"~"*163,"~"*163,"~"*163,"~"*163,"~"*163,"~"*163,"~"*163,"~"*163]

with open("battleship.c","r") as src:
    lines = src.read().split("\n")[210:-5]

currentRow = 0
for line in lines:
    if "// Check Row" in line:
        hashtag = line.index("#")
        currentRow = int(line[hashtag+1:]) - 1

    elif "if(master" in line:
        endIndex = line.rfind("]")
        column = int(line[17:endIndex])
        battleshipMap[currentRow] = battleshipMap[currentRow][:column] + "B" + battleshipMap[currentRow][column+1:]

with open("map.txt","w") as ownMap:
    ownMap.write("9 163\n")
    for row in battleshipMap:
        ownMap.write(row + "\n")

