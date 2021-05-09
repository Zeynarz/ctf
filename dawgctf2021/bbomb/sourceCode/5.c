uint phase5(long param_1)

{
  uint uVar1;
  void *input;
  undefined8 uVar2;
  uint local_1c;
  int ans;
  int local_14;
  
  puts("\nAre you really, really ready and excited for this stage?");
  local_1c = 1;
  uVar2 = 0x1016c4;
  input = calloc(4,4);
  getInput(5,param_1,"%d%d%d%d",input,(long)input + 4,(long)input + 8,(long)input + 0xc,uVar2);
  ans = 0;
  local_14 = 0;
  while (local_14 < 4) {
    if ((0 < local_14) &&
       ((int)*(char *)(param_1 + (long)local_14 + -1) < *(char *)(param_1 + local_14) + -10)) {
      local_1c = 0;
    }
    uVar1 = func5(*(input + local_14 * 4)); 
    local_1c = local_1c & uVar1;//last bit need to be one
    ans = ans + *(input + local_14 * 4); 
    local_14 = local_14 + 1;
  }
  if (ans != 0x1f94) { //8084
    local_1c = 0;
  }
  free(input);
  return local_1c;
}
