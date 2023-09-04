#!/usr/bin/python3

import os
import gmpy2
import random
import sys

import pathlib
from Crypto.PublicKey import RSA



def welcome():
    text = '''

           ,,                              ,,
 .M"""bgd  db                            `7MM              `7MM"""Mq.   .M"""bgd      db
,MI    "Y                                  MM                MM   `MM. ,MI    "Y     ;MM:
`MMb.    `7MM  `7MMpMMMb.pMMMb. `7MMpdMAo. MM  .gP"Ya        MM   ,M9  `MMb.        ,V^MM.
  `YMMNq.  MM    MM    MM    MM   MM   `Wb MM ,M'   Yb       MMmmdM9     `YMMNq.   ,M  `MM
.     `MM  MM    MM    MM    MM   MM    M8 MM 8M""""""       MM  YM.   .     `MM   AbmmmqMA
Mb     dM  MM    MM    MM    MM   MM   ,AP MM YM.    ,       MM   `Mb. Mb     dM  A'     VML
P"Ybmmd" .JMML..JMML  JMML  JMML. MMbmmd'.JMML.`Mbmmd'     .JMML. .JMM.P"Ybmmd" .AMA.   .AMMA.
                                  MM
                                .JMML.
'''
    print(text)
    rsa_key = RSA.generate(1024)
    return rsa_key

def get_int_length(num:int):
    import math
    return int(math.ceil(num.bit_length() / 8))

def RSAencrypt(plaintext:bytes, e:int, N:int):
    int_plaintext = int.from_bytes(plaintext, 'big')
    ciphertext = pow(int_plaintext, e, N)
    return ciphertext.to_bytes(get_int_length(ciphertext),'big').hex()

def RSAdecrypt(ciphertext:bytes, d:int, N:int):
    int_ciphertext = int.from_bytes(ciphertext, 'big')
    message = pow(int_ciphertext, d, N)
    return message.to_bytes(get_int_length(message), 'big')

def action_seeflag(key):
    flagfile = pathlib.Path("/home/ctf/flag")
    with open (flagfile, 'r') as f:
        flag = f.read()
    data = flag.encode().hex().encode()
    result = RSAencrypt(data, key.e, key.n)
    print(f"FLAG is {result}")
    return

def action_encrypt(key:RSA.RsaKey):
    user_inp = input("write plain text(hex string format): ")
    userInput_hex = bytes.fromhex(user_inp)
    result = RSAencrypt(userInput_hex, key.e, key.n)
    print(f"[*] Done! Here is!\n {result}")
    return

def action_decrypt(key):

    ciphertext = input("write ciphertext with hex string format: ")
    flagfile = pathlib.Path("/home/ctf/flag")
    with open (flagfile, 'r') as f:
        cmp_flag = f.read()
    data = cmp_flag.encode().hex().encode()
    userInput_hex = bytes.fromhex(ciphertext)
    decrypted_data = RSAdecrypt(userInput_hex, key.d, key.n)
    if(RSAencrypt(data, key.e, key.n) == ciphertext):
        print("Don't decrypt encrpted flag...")
        return

    print(f"[*] decrypt result => {decrypted_data.hex()}")


def main(rsakey):
    action = int(input("1. encrypt\n2. decrypt\n3. see top secret\n4. exit\n> "))
    if action == 1:
        action_encrypt(rsakey)
    elif action == 2:
        action_decrypt(rsakey)
    elif action == 3:
        action_seeflag(rsakey)
    elif action == 4:
        print("byebye!")
        sys.exit()
    else:
        print("Invalid input!!")


if __name__ == '__main__':
    initkey = welcome()
    for _ in range(100000):
        print("\nYou can encrypt / decrypt with my SIMPLE RSA!")
        try: main(initkey)
        except Exception as e:
            print(e)

