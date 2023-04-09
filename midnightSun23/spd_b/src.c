undefined4 main(undefined4 param_1,undefined4 param_2,undefined4 param_3) {
  int iVar1;
  undefined4 uVar2;
  undefined4 local_2c;
  undefined local_28;
  int local_24;
  undefined *local_14;
  
  local_14 = &param_1;
  setvbuf(stdin,(char *)0x0,2,0);
  setvbuf(stdout,(char *)0x0,2,0);
  iVar1 = getrandom(&sec,4,1);
  if (iVar1 == 4) {
    local_28 = 0;
    banner();
    clear(param_2,param_3);
    local_24 = 0;
    while (local_24 < 3) {
      iVar1 = guess("%12s");
      if (iVar1 == 0) {
        puts("\x1b[32;1mwow:\x1b[0m you win!");
        break;
      }
      local_24 = local_24 + 1;
    }
    if (local_24 == 3) {
      printf("\x1b[31;1merror:\x1b[0m you could not guess my number (%d)!\n",sec);
    }
    uVar2 = 0;
  }
  else {
    perror("getrandom failed");
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

undefined4 guess(undefined4 param_1) {
  int iVar1;
  char local_8c [132];

  printf("guess: ");
  iVar1 = __isoc99_scanf(param_1,local_8c);
  if ((iVar1 != 0) && (iVar1 = check(local_8c), iVar1 == 0)) {
    return 0;
  }
  printf(local_8c);
  puts(" is not my number :(");
  return 0xffffffff;
}


undefined4 check(char *param_1){
  int iVar1;
  undefined4 uVar2;

  iVar1 = atoi(param_1);
  if (iVar1 == sec) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}
