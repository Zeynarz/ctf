undefined4 phase2(undefined8 param_1)

{
  char *__s;
  size_t sVar1;
  undefined4 returnValue;
  int loopNum;
  
  puts("\nCan you help me find my lost key so I can read my string?");
  returnValue = 1;
  __s = (char *)calloc(0x29,1);
  getInput(2,param_1,&DAT_001028d1,__s);
  loopNum = 0;
  while( true ) {
    sVar1 = strlen("Dk52m6WZw@s6w0dIZh@2m5a");
    if (sVar1 <= (ulong)(long)loopNum) break;
    sVar1 = strlen(__s);
    if (sVar1 <= (ulong)(long)loopNum) break;
    if ("Dk52m6WZw@s6w0dIZh@2m5a"[loopNum] != (byte)(__s[loopNum] ^ 5U)) {
      returnValue = 0;
    }
    loopNum = loopNum + 1;
  }
  sVar1 = strlen("Dk52m6WZw@s6w0dIZh@2m5a");
  if ((long)loopNum != sVar1) {
    returnValue = 0;
  }
  free(__s);
  return returnValue;
}
