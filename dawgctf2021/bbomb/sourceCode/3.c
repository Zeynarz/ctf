bool phase3(undefined8 param_1)

{
  int iVar1;
  char *heapAddr;
  char *pcVar2;
  char *local_20;
  
  puts("\nReflections? Rotations? Translations? This is starting to sound like geometry...");
  heapAddr = (char *)calloc(0x29,1); 
  getInput(3,param_1,&DAT_001028d1,heapAddr);
  local_20 = heapAddr;
  while (*local_20 != '\0') {
    pcVar2 = (char *)func3_1(local_20);
    *local_20 = *pcVar2; //same thing? whatever inside heap address is whatever inside heap address
    pcVar2 = (char *)func3_2(local_20);
    *local_20 = *pcVar2;
    local_20 = local_20 + 1;
  }
  iVar1 = strcmp(heapAddr,"\"_9~Jb0!=A`G!06qfc8\'_20uf6`2%7");check if they are equal
  free(heapAddr); 
  return iVar1 == 0;if they are equal then return 1
}
//rmb 0 is false 1 and other is true
//defuse doesnt want 0
