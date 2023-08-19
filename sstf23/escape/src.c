undefined8 main(void){
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  char *pcVar4;
  long in_FS_OFFSET;
  code *local_a8;
  size_t mmapLen;
  char buf [136];
  long local_10;
  
  iVar1 = FUN_00101289(); // setup sandbox
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  } else {
    // if everything in sandbox is setup nicely, do this:
    lVar3 = FUN_00101492(&shellcode,&mmapLen);
    if (lVar3 == 0) {
      uVar2 = 0xffffffff;
    }
    else {
      memset(shellcode,0x90,mmapLen); // fill it with nops
      shellcode[mmapLen - 1] = (code)0xc3; // put a ret instruction at the end
      while( true ) {
        puts("Enter: ");
        fflush(stdout);
        pcVar4 = fgets(buf,0x80,stdin);
        if (pcVar4 != buf) break; // fgets() returns s on success
        iVar1 = strncmp(buf,"done",4);
        if (iVar1 == 0) {
          (*shellcode)();
          munmap(shellcode,mmapLen);
          uVar2 = 0;
          goto LAB_0010166a;
        }
        printf("Entered: ");
        printf(buf);
        fflush(stdout);
      }
      uVar2 = 0xfffffffe;
    }
  }
LAB_0010166a:
  return uVar2;
}

void * FUN_00101492(void **param_1,size_t *param_2){
  size_t __len;
  void *mmapChunk;

  __len = sysconf(0x1e); // prob just getting the page size
  mmapChunk = mmap(0x50510000,__len,7,0x32,-1,0);
  if (mmapChunk == (void *)0xffffffffffffffff) {
    mmapChunk = (void *)0x0;
  }
  else {
    *param_1 = mmapChunk;
    *param_2 = __len;
  }
  return mmapChunk;
}

bool FUN_00101289(void){
  // https://man7.org/linux/man-pages/man2/prctl.2.html
  // weaken execve 
  iVar1 = prctl(PR_SET_NO_NEW_PRIVS,1,0,0,0);
  if (iVar1 == -1) {
    bVar2 = false;
  } else {
    local_98 = 0x20;
    local_96 = 0;
    local_95 = 0;
    local_94 = 0;
    local_90 = 0x35;
    local_8e = 0xb;
    local_8d = 0;
    local_8c = 0x40000000;
    local_88 = 0x15;
    local_86 = 10;
    local_85 = 0;
    local_84 = 0x3b;
    local_80 = 0x15;
    local_7e = 9;
    local_7d = 0;
    local_7c = 0x142;
    local_78 = 0x15;
    local_76 = 8;
    local_75 = 0;
    local_74 = 0x101;
    local_70 = 0x15;
    local_6e = 7;
    local_6d = 0;
    local_6c = 2;
    local_68 = 0x15;
    local_66 = 6;
    local_65 = 0;
    local_64 = 0x5a;
    local_60 = 0x15;
    local_5e = 5;
    local_5d = 0;
    local_5c = 0x5b;
    local_58 = 0x15;
    local_56 = 4;
    local_55 = 0;
    local_54 = 0x5c;
    local_50 = 0x15;
    local_4e = 3;
    local_4d = 0;
    local_4c = 0x5d;
    local_48 = 0x15;
    local_46 = 2;
    local_45 = 0;
    local_44 = 0x5e;
    local_40 = 0x15;
    local_3e = 1;
    local_3d = 0;
    local_3c = 0x50;
    local_38 = 0x15;
    local_36 = 0;
    local_35 = 2;
    local_34 = 0x51;
    local_30 = 6;
    local_2e = 0;
    local_2d = 0;
    local_2c = 0;
    local_28 = 6;
    local_26 = 0;
    local_25 = 0;
    local_24 = 0x7ff00000;
    local_20 = 6;
    local_1e = 0;
    local_1d = 0;
    local_1c = 0x7fff0000;
    local_a8[0] = 0x10;
    local_a0 = &local_98;
    // https://man7.org/linux/man-pages/man2/seccomp.2.html
    // syscalls allowed are defined using a BPF, which is stored in
    // the form of struct sock_fprog

    // https://github.com/gebi/teach-seccomp/blob/master/step-2/example.c
    iVar1 = prctl(PR_SET_SECCOMP,SECCOMP_MODE_FILTER,local_a8);
    bVar2 = iVar1 != -1;
  }
  return bVar2;
}

