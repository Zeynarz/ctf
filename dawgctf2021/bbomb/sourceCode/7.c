uint phase7(undefined8 param_1)

{
  undefined uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined8 *mallocAddr;
  void *pvVar5;
  uint returnValue;
  int i;
  int sum;
  int n;
  int local_28;
  int local_24;
  
  puts("\nAt least we can say our code is resuable");
  returnValue = 1;
  mallocAddr = (undefined8 *)malloc(0x18);
  i = 0;
  while (i < 3) {
    pvVar5 = calloc(0x29,1);
    mallocAddr[i] = pvVar5;
    i = i + 1;
  }
  getInput(7,param_1,"%s%s%s",*mallocAddr,mallocAddr[1],mallocAddr[2]);
  sum = 0;
  n = 0;
  do 
    if (2 < n) { //final
      if (sum != 0x1fd) {
        returnValue = 0;
      }
      local_24 = 0;
      while (local_24 < 3) {
        free(mallocAddr[local_24]);
        local_24 = local_24 + 1;
      }
      free(mallocAddr);
      return returnValue;
    }
    iVar2 = atoi(mallocAddr[n]);
    sum = sum + iVar2;
    if (0 < n) {
      iVar2 = atoi(mallocAddr[n + -1]);//0
      iVar3 = atoi(mallocAddr[n]);     //1
      if (iVar3 < iVar2) {
        returnValue = 0;
      }
    }
    local_28 = 0;
    while (local_28 < 3) { //every round
      iVar2 = atoi(mallocAddr[n]);
      if (iVar2 < 100) {
        returnValue = 0;
        break;
      }
      iVar2 = atoi(mallocAddr[n]);
      uVar4 = func5(iVar2);
      returnValue = returnValue & uVar4;
      uVar1 = *(mallocAddr[n] + 2);
      *(mallocAddr[n + 2]) = *(mallocAddr[n + 1]);
      *(mallocAddr[n + 1]) = *mallocAddr[n];
      *mallocAddr[n] = uVar1;
      local_28 = local_28 + 1;
    }
    n = n + 1;
  } while( true );
}
