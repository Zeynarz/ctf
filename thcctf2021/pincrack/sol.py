#Run with python sol.py
import hashlib
for i in range(999999 + 1):
    password = "0" *( 6 - len(str(i))) + str(i)
    h = hashlib.sha1(password)
    hashed = h.hexdigest()[:16]
    if (hashed == "d3ffeed407ad7ad6"):
        print("Found!")
        print(password + ": " + hashed)
        break;

password = list(password)
temp = password[:]
password[0] = temp[4]
password[2] = temp[3]
password[3] = temp[0]
password[4] = temp[2]

key = ""
for i in password:
    key += i

print("The pin: " + key)
