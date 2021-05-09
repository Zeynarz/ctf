uint phase8(undefined8 param_1)

{
  int iVar1;
  size_t sVar2;
  ulong uVar3;
  long in_FS_OFFSET;
  undefined4 local_44;
  int local_40;
  uint local_3c;
  undefined8 local_38;
  char *local_30;
  char *local_28;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  puts("\nGo touch grass!");
  local_30 = "T30G343DDERh_TWT_e_ror";
  local_28 = (char *)calloc(0x29,1);
  getInput(8,param_1,&DAT_001028d1,local_28);
  local_38 = 0;
  local_40 = 0;
  while( true ) { //iterate over input
    uVar3 = SEXT48(local_40);
    sVar2 = strlen(local_30);
    if (sVar2 <= uVar3) break;
    local_38 = func8_1((local_28[local_40],local_38,local_38); //0
    local_40 = local_40 + 1;
  }
  local_44 = 0;
  func8_2(local_38,local_28,&local_44,local_28);
  func8_3(local_38);
  iVar1 = strcmp(local_28,local_30);
  local_3c = (uint)(iVar1 == 0);
  free(local_28);
  return local_3c;
}

