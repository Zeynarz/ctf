void vuln(void){
  long lVar1;
  undefined8 *puVar2;
  long in_FS_OFFSET;
  byte bVar3;
  undefined8 local_218;
  undefined8 local_210;
  undefined8 local_208 [63];
  long local_10;
  
  bVar3 = 0;
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  printf("input> ");
  local_218 = 0;
  local_210 = 0;

  // whats the point of this?
  // to make recalling the function troublesome?
  lVar1 = 0x3e;
  puVar2 = local_208;
  while (lVar1 != 0) {
    lVar1--1;
    *puVar2 = 0;
    puVar2 = puVar2 + (ulong)bVar3 * -2 + 1;
  }

  read(0,&local_218,0x300);
  printf("Your input> ");
  printf("%s",&local_218);
  
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
    __stack_chk_fail();
  }
  return;
}
