#!/usr/bin/python3
from hashlib import md5
from Crypto.Cipher import AES
from base64 import *
#from secret import secret_key,flag

BS = 16
KEY = b"A"*16
FLAG = "FAKEFLAG"

pad = lambda s: s + (BS - len(s) % BS) * \
                chr(BS - len(s) % BS)
unpad = lambda s: s[:-ord(s[len(s) - 1:])]

def encrypt(raw):
    raw = pad(raw)
    cipher = AES.new(KEY, AES.MODE_ECB)
    return b64encode(cipher.encrypt(raw.encode('utf8')))

def decrypt(enc):
    enc = b64decode(enc)
    cipher = AES.new(KEY, AES.MODE_ECB)
    return unpad(cipher.decrypt(enc)).decode('utf8')

def main():
    while True:
        print ("""
========= Your Behavior =========
1. EXPERIMENT
2. SUBMIT
3. CLOSE
""")
        behavior = int(input("your behavior > "))
        if behavior == 1:
            print ("I'm a crypto genius")    
            input_data = input("Do you want to experiment? > ")

            if len(input_data) > 200:
                print ("It's still too much...")
            else:
                enc = encrypt(input_data)
                print (enc)

        elif behavior == 2:
            input_data = input ("Did you already solve the trick? > ")
            try:
                dec = decrypt(input_data)
                print(dec)
                print(len(dec))
                if len(dec) == 128 and dec == "6230ee81ac9d7785a16c75b93a89de9cbb9cbb2ddabaaadd035378c36a44eeacb371322575b467a4a3382e3085da281731557dadd5210f21b75e1e9b7e426eb7":
                    print (f"flag : {FLAG}")
                else:
                    print ("you're still far away")
            except:
                print ("you're still far away")
                continue


        elif behavior == 3:
            print ("BYE ... ")
            break
        else:
            print("[*] Invalid input")

if __name__ == '__main__':
    main ()


