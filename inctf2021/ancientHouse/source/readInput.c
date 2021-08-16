void FUN_00101351(char *param_1,uint param_2)

{
  ssize_t sVar1;
  size_t sVar2;
  
  sVar1 = read(0,param_1,param_2);
  if (sVar1 < 1) {
    puts("Error ");
    exit(0);
  }
  sVar2 = strlen(param_1);
  if (param_1[(long)(int)sVar2 + -1] == '\n') {
    param_1[(long)(int)sVar2 + -1] = '\0';
  }
  return;
}
