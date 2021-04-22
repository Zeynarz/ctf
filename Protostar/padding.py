combiningLetters = ""
for i in range(0,26):
    alphabet = chr(0x41 + i ) * 4
    combiningLetters += alphabet
    
print combiningLetters
    

