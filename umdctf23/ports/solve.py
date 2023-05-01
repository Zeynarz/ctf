# Removed the zip files and txt files cause they're very large in total 
# and I dont want to store them in my github

from zipfile import ZipFile

currentPort = 1
while True:
    print(currentPort)
    zipName = "port-" + str(currentPort) + ".txt.zip"
    currentZip = ZipFile(zipName,"r")
    currentZip.extractall(".",pwd=bytes(str(currentPort).encode()))
    currentZip.close()
    
    txtName = zipName[:-4]
    currentTxt = open(txtName,"r")
    contents = currentTxt.read()

    if "UMDCTF{" in contents:
        print(contents)
        break
    else:
        endIndex = contents.find(" instead :(")
        currentPort = int(contents[11:endIndex])


    
