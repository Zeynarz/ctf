undefined8 main(void) {
  long lVar1;
  long in_FS_OFFSET;
  char buf [24];
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  setup();
  puts("Welcome to the SEETF note sandbox!");
  puts("======================================");
  puts("======================================");
  while (exit != 0) {
    menu();
    read(0,buf,0x640);
    lVar1 = atol(buf);
    if (lVar1 == 4) {
      exit = 0;
    }
    else {
      if (lVar1 < 5) {
        if (lVar1 == 3) {
          read();
        }
        else {
          if (lVar1 < 4) {
            if (lVar1 == 1) {
              createNote();
            }
            else {
              if (lVar1 == 2) {
                write();
              }
            }
          }
        }
      }
    }
  }
  seccompInit();
  puts("Bye!");
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
  __stack_chk_fail();
}

bool createNote(void){
  uint uVar1;
  void *pvVar2;
  
  uVar1 = n;
  if (n < 100) {
    pvVar2 = mmap(0x0,0x1000,3,0x22,0,0);
    *(notes + n * 8) = pvVar2;
    printf("Note created id %d\n",n);
    printf("Addr of note %d is 0x%llx\n",n,pvVar2);
    n = n + 1;
  }
  else {
    puts("Note full, cant create anymore!!!!!!!");
  }
  return uVar1 < 100;
}

undefined8 write(void){
  undefined8 uVar1;
  long in_FS_OFFSET;
  uint idx;
  long local_10;

  local_10 = *(in_FS_OFFSET + 0x28);
  idx = 0;
  printf("idx = ");
  __isoc99_scanf("%d",&idx);
  if (idx < n) {
    printf("size to write = ");
    __isoc99_scanf("%d",sizes + idx * 4);
    if (*(sizes + idx * 4) < 0x1001) {
      read(0,*(notes + idx * 8),*(sizes + idx * 4));
      uVar1 = 1;
    }
    else {
      puts("too much");
      uVar1 = 0;
    }
  }
  else {
    puts("invalid idx");
    uVar1 = 0;
  }
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
    __stack_chk_fail();
  }
  return uVar1;
}

bool read(void){
  long in_FS_OFFSET;
  bool bVar1;
  uint idx;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  idx = 0;
  printf("idx = ");
  __isoc99_scanf("%d",&idx);
  if (idx < n) {
    write(1,*(notes + idx * 8),*(sizes + idx * 4));
  }
  else {
    puts("invalid idx");
  }

  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
    __stack_chk_fail();
  }
  return bVar1;
}




void seccompInit(void) {
  int iVar1;
  undefined8 uVar2;

  uVar2 = seccomp_init(0);

  iVar1 = seccomp_rule_add(uVar2,0x7fff0000,2,0);
  if (iVar1 != 0) {
    __assert_fail("seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(open), 0) == 0","./chall.c",0x16,
                  "filter");
  }

  iVar1 = seccomp_rule_add(uVar2,0x7fff0000,0x101,0);
  if (iVar1 != 0) {
    __assert_fail("seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(openat), 0) == 0","./chall.c",0x17
                  ,"filter");
  }

  iVar1 = seccomp_rule_add(uVar2,0x7fff0000,1,0);
  if (iVar1 != 0) {
    __assert_fail("seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(write), 0) == 0","./chall.c",0x18,
                  "filter");
  }

  iVar1 = seccomp_rule_add(uVar2,0x7fff0000,9,0);
  if (iVar1 != 0) {
    __assert_fail("seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mmap), 0) == 0","./chall.c",0x19,
                  "filter");
  }

  iVar1 = seccomp_rule_add(uVar2,0x7fff0000,0xe7,0);
  if (iVar1 != 0) {
    __assert_fail("seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(exit_group), 0) == 0","./chall.c",
                  0x1a,"filter");
  }

  iVar1 = seccomp_load(uVar2);
  if (iVar1 != 0) {
    __assert_fail("seccomp_load(ctx) == 0","./chall.c",0x1b,"filter");
  }
  return;
}
