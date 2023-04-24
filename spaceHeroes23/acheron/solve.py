from pwn import *
io = remote("spaceheroes-acheron.chals.io", 443, ssl=True, sni="spaceheroes-acheron.chals.io")
io.sendlineafter("You gotta navigate your way back to your ship!","NENWSSEWSNENSSWEENWSNNESS")
io.interactive()
