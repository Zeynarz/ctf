void main(void){
  undefined *puVar1;
  int iVar2;
  undefined8 uVar3;
  long in_FS_OFFSET;
  char buf [8];
  code *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_20;
  
  local_20 = *(undefined8 *)(in_FS_OFFSET + 0x28);
  setbuf(stdin,(char *)0x0);
  setbuf(stdout,(char *)0x0);
  alarm(10);

  local_38 = printf;
  local_30 = 0;
  local_2c = 0;

  uVar3 = libc("libc.so.6",2);
  puts("You have only 3 chances to win the game.");
  puts("\nThe 1st chacne: Get libc symbol info.");
  showFuncAddr(uVar3);
  puts("\nThe 2nd chacne: Get libc symbol info.");
  showFuncAddr(uVar3);
  puts("\nTwo strikes against you. Now that you have only ONE chance.");
  printf("Can you guess the pitcher\'s selection?\n > ");

  fgets(buf,0x10,stdin);
  puVar1 = pitches;
  // 0x0000555555558010│+0x0000: 0x0000555555556053  →  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
  iVar2 = rand();
  if (local_40[0] == puVar1[iVar2 % 0x1a]) {
    (*local_38)(" You hit the ball! It\'s an amazing walk-off homerun. Your team won the game.\n");
  }
  else {
    (*local_38)(" Struck out. Game Over - You got %d hits and %d runs.\n",local_30,local_2c,local_38
               );
  }
  dlclose(uVar3);
  exit(0);
}

void showFuncAddr(undefined8 param_1){
  size_t sVar1;
  long in_FS_OFFSET;
  undefined8 local_50;
  undefined8 local_40;
  char local_38 [40];
  long local_10;

  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  printf(" > ");
  fgets(local_38,0x20,stdin);
  sVar1 = strlen(local_38);
  local_50 = param_1;
  if (local_38[sVar1 - 1] == '\n') {
    sVar1 = strlen(local_38);
    local_38[sVar1 - 1] = '\0';
  }
  local_40 = dlsym(local_50,local_38,local_38);
  if (local_40 == 0) {
    printf(" Libc doesn\'t have function \'%s\'.\n",local_38);
  }
  else {
    printf(" Libc function \'%s\' is at %p.\n",local_38,local_40);
  }
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
    __stack_chk_fail();
  }
  return;
}
