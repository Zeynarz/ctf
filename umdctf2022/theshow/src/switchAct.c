void switchAct(void)

{
  int iVar1;
  char *cryptRetVal;
  long in_FS_OFFSET;
  int i;
  undefined actName [32];
  char actCode [72];
  long local_10;
  
  printf("Name of Act: ");
  __isoc99_scanf("%s",actName);
  printf("Act Code: ");
  __isoc99_scanf("%s",actCode);
  cryptRetVal = crypt(actCode,salt);
  i = 0;
  while (i < 0x10) {
    iVar1 = __strncmp(*(actList + i*8),actName,0x20);
    if (iVar1 == 0) {
      iVar1 = __strncmp(*(actList + i*8) + 0x20,cryptRetVal,0x40);
      if (iVar1 == 0) {
        currentAct = *(actList + i * 8);
      }
    }
    i = i + 1;
  }
  return;
}
