undefined4 phase1(undefined8 param_1)

{
  char *__s;
  size_t sVar1;
  size_t sVar2;
  undefined4 local_34;
  int local_30;
  
  puts(
      "\nStarting off easy... reversing (things) is fun! (Wrap all flags in DawgCTF{} when submitting to the scoreboard)"
      );
  local_34 = 1;
  heapAddr = (char *)calloc(0x29,1);
  getInput(1,param_1,&DAT_001028d1,heapAddr);
  loopNum = 0;
  sVar1 = strlen(heapAddr)41;
  while( true ) {
    sVar2 = 20;
    if (20 <= (ulong)(long)loopNum) break;
    sVar2 = strlen(heapAddr)41;
    if (sVar2 <= (ulong)(long)loopNum) break;
    if ("Gn1r7s_3h7_Gn15Rev3R"[loopNum] != heapAddr[(long)((int)sVar1 - loopnum) + -1]) {
      local_34 = 0;
    }
    loopNum = loopNum + 1;
  }
  sVar1 = strlen("Gn1r7s_3h7_Gn15Rev3R");
  if ((long)local_30 != sVar1) {
    local_34 = 0;
  }
  free(__s);
  return local_34;
}
