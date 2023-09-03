undefined4 main(void){
  char permissions [5];
  char privKey [0x30];
  char remainingInfo [0x108];
  long local_10;
  
  local_14c = 0;
  if (isInitialized == 0) {
    isInitialized = 1;
    setvbuf(stdin,(char *)0x0,2,0);
    setvbuf(stdout,(char *)0x0,2,0);
    i = 0;
    while (i < 0x100) {
      i2 = SEXT48(i);
      j = 0;
      while (j < 8) {
        if ((i2 & 1) == 0) {
          // if i2 is odd
          i2 = i2 >> 1;
        }
        else {
          // if i2 is even
          i2 = i2 >> 1 ^ 0x95ac9329ac4bc9b5;
        }
        j = j + 1;
      }
      *(&DAT_001040c0 + i * 8) = i2;
      i = i + 1;
    }

    f = fopen("/proc/self/maps","r");
    if (f == (FILE *)0x0) {
      printf("Could not open file.\n");
      local_14c = 1;
      goto LAB_00101a69;
    }

    memset(permissions,0,5);
    memset(remainingInfo,0,0x100);
    // read from mapping file and put into these vars
    while (size = __isoc99_fscanf(f,"%lx-%lx %4s",&head,&end,permissions),
          size != -1) {
      // clears out the unnecessary info
      fgets(remainingInfo,0x100,f);
      pcVar5 = strstr(permissions,"w");
      if (((pcVar5 != 0x0) && (pcVar5 = strstr(remainingInfo,"heap"), pcVar5 == (char *)0x0)) &&
         (pcVar5 = strstr(remainingInfo,"stack"), pcVar5 == (char *)0x0)) {
        // memory found is writable, and not the stack or heap
        globalHead = head;
        calculatedAddr = algo1(&globalHead,8);
        __addr = (calculatedAddr << 0xc);
        mapLen = end - head;
        
        // create a memory region at the calculated address
        // and copy from the initial region to the new region
        mmap(__addr,mapLen,3,0x21,-1,0);
        memcpy(__addr,head,mapLen);
        printf("Saved : 0x%lx\n",__addr);
        *(&flashMemLen + mapN * 8) = mapLen;
        *(&flashMemAddrs + mapN * 8) = __addr;
        lVar1 = mapN * 8;
        mapN = mapN + 1;
        *(&initialMapHeads + lVar1) = head;
      }
    }
    printf("======================================\n");
  }
  do {
    menu();
    uVar4 = readInt();
    switch(uVar4) {
    case 0:
      goto switchD_00101876_caseD_5;
    case 1:
      loadMem();
      main();
      break;
    case 2:
      // allocate memory
      if (newOwnFlash == (void *)0x0) {
        memset(privKey,0,0x21);
        printf("PrivKey :> ");
        getInput(privKey,0x20);
        printf("Size :> ");
        size = readInt();
        newFlashSize = SEXT48(size);
        // if we input null, then strlen result will be 0
        mapLen = strlen(privKey); // privKeyLen actually
        calculatedAddr = algo1(privKey,mapLen);
        mmap((calculatedAddr << 0xc),newFlashSize,3,0x21,-1,0);
        newOwnFlash = (calculatedAddr << 0xc);
        printf("Your Map: %p\n");
      }
      break;
    case 3:
      // read memory
      if (newOwnFlash != 0x0) {
        printf("Index :> ");
        index = readInt();
        index = SEXT48(index);
        if (index < newFlashSize) {
          // print stuff out from newOwnFlash starting from index
          // negative addressing vuln?
          write(1,(newOwnFlash + index),newFlashSize - index);
        }
      }
      break;
    case 4:
      // write memory
      if (newOwnFlash != (void *)0x0) {
        printf("Index :> ");
        index = readInt();
        index = SEXT48(size);
        if (index < newFlashSize) {
          read(0,(newOwnFlash + index),newFlashSize - index);
        }
      }
      break;
    default:
      goto switchD_00101876_caseD_5;
    }
  } while( true );



switchD_00101876_caseD_5:
  local_14c = 0;
LAB_00101a69:
  if (*(long *)(in_FS_OFFSET + 0x28) == local_10) {
    return local_14c;
  }
}

uint algo1(long mapHead,ulong n){
  uint uVar1;
  int j;
  ulong i;
  uint local_1c;

  local_1c = 0xffffffff;
  i = 0;
  while (i < n) {
    // byte xor int
    // overflow if n > 8
    local_1c = *(byte *)(mapHead + i) ^ local_1c;
    j = 0;
    while (j < 8) {
      uVar1 = 0;
      if ((local_1c & 1) != 0) {
        // if local_1c odd
        uVar1 = 0xedb88320;
      }
      local_1c = local_1c >> 1 ^ uVar1;
      j = j + 1;
    }
    i = i + 1;
  }

    // this essentially just permutates the address
    // there is prob a way to reverse it
  return local_1c ^ 0xffffffff;
}


void loadMem(void){
  int i;

  i = 0;
  while ((ulong)(long)i < mapN) {
    // load the memory from the flash memory into the actual addresses
    memcpy(*(&initialMapHeads + (long)i * 8),
           *(&flashMemAddrs + (long)i * 8),*(size_t *)(&flashMemLen + (long)i * 8));
    i = i + 1;
  }
  return;
}
