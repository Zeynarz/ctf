undefined  [16] main(void) {
  int iVar1;
  long lVar2;
  ssize_t sVar3;
  long in_FS_OFFSET;
  int local_60;
  void *local_58;
  void *local_50;
  void *local_48;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  setvbuf(stdin,(char *)0x0,2,0);
  setvbuf(stdout,(char *)0x0,2,0);
  signal(0xe,done);
  alarm(0x3c);
  banner();
  lVar2 = getrandom(&local_58,8,1);
  if (lVar2 == 8) {
    local_58 = (void *)((ulong)local_58 & 0x7ffffffff000);
    local_50 = mmap(local_58,0x1000,3,0x32,-1,0);
    if (local_50 == (void *)0xffffffffffffffff) {
      perror("mmap failed, addr");
    }
    else {
      printf("c0de: ");
      sVar3 = read(0,local_50,0x1000);
      if ((int)sVar3 < 0) {
        perror("read failed");
      }
      else {
        local_48 = local_50;
        local_60 = 0;
        while (local_60 < (int)sVar3) {
          // no "/" or "bin" or "sh" or b"\x00"
          if ((
                (local_50[local_60] == '/') || ((
                (local_50[local_60] == 'b' && (local_50[local_60 + 1] == 'i'))
                && (local_50[local_60 + 2] == 'n')))) 

                ||

             (((local_50[local_60] == 's' &&
               (local_50[local_60 + 1] == 'h')) ||
              (local_50[local_60] == '\0')))) {
            puts("nope");
            goto LAB_001015b2;
          }
          local_60 = local_60 + 1;
        }
        iVar1 = mprotect(local_50,0x1000,5);
        if (iVar1 != -1) {
          return CONCAT88(0xfffffffffffffffc,0xffffffffffffffff);
        }
        perror("mprotect failed");
      }
    }
  }
  else {
    perror("getrandom failed");
  }
LAB_001015b2:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return ZEXT816(1);
}
