from pwn import * 
io = remote("spaceheroes-galactic-federation.chals.io", 443, ssl=True, sni="spaceheroes-galactic-federation.chals.io")

usernameObf = "hktpu"
passwordObf = "8fs7}:f~Y;unS:yfqL;uZ"

username = ""
password = ""

for char in usernameObf:
    username += chr(ord(char) - 7)

for char in passwordObf:
    password += chr(ord(char) - 7)

io.sendlineafter("USERNAME:",username)
io.sendlineafter("PASSWORD:",password)

io.sendlineafter(">>","presidential_decree")
io.sendlineafter(">>","change_galactic_currency")
io.sendlineafter("What will the galaxy's new form of currency be called?","usd")
io.sendlineafter(">>","go_back")


io.sendlineafter(">>","adjust_economy")
io.sendlineafter(">>","inflate_currency")
io.sendlineafter("How much would you wish to inflate the economy by? (enter percentage)","-100")

io.interactive()
