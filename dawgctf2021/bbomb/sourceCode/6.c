undefined4 phase6(undefined8 param_1)

{
  char *heapAddress;
  size_t sVar1;
  long in_FS_OFFSET;
  undefined4 local_48;
  int loopNum;
  char arr [4];
  undefined local_34;
  undefined local_33;
  undefined local_32;
  undefined local_31;
  undefined local_30;
  undefined local_2f;
  undefined local_2e;
  undefined local_2d;
  undefined local_2c;
  undefined local_2b;
  undefined local_2a;
  undefined local_29;
  undefined local_28;
  undefined local_27;
  undefined local_26;
  undefined local_25;
  undefined local_24;
  undefined local_23;
  undefined local_22;
  undefined local_21;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  puts("\nOh no... I lost the key to my string again :(");
  local_48 = 1;
  arr[0] = '@';
  arr[1] = 0x77;
  arr[2] = 0x23;
  arr[3] = 0x91;
  local_34 = 0xb0;
  local_33 = 0x72;
  local_32 = 0x82;
  local_31 = 0x77;
  local_30 = 99;
  local_2f = 0x31;
  local_2e = 0xa2;
  local_2d = 0x72;
  local_2c = 0x21;
  local_2b = 0xf2;
  local_2a = 0x67;
  local_29 = 0x82;
  local_28 = 0x91;
  local_27 = 0x77;
  local_26 = 0x26;
  local_25 = 0x91;
  local_24 = 0;
  local_23 = 0x33;
  local_22 = 0x82;
  local_21 = 0xc4;
  heapAddress = calloc(0x29,1);
  getInput(6,param_1,&DAT_001028d1);
  loopNum = 0;
  while( true ) {
    sVar1 = strlen(arr) 4;
    if (sVar1 <= loopNum) break;
    sVar1 = strlen(heapAddress) input;
    if (sVar1 <= loopNum) break;
    heapAddress[loopNum] = (heapAddress[loopNum] << 4) | heapAddress[loopNum] >> 4;
    heapAddress[loopNum] = heapAddress[loopNum] ^ 100;
    if (heapAddress[loopNum] != arr[loopNum]) {
      local_48 = 0;
    }
    loopNum = loopNum + 1;
  }
  sVar1 = strlen(arr);
  if ((long)loopNum != sVar1) {
    local_48 = 0;
  }
  free(heapAddress);
  if (local_20 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    heapAddresstack_chk_fail();
  }
  return local_48;
}
