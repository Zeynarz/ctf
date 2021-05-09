undefined4 phase4(undefined8 param_1)

{
  long lVar1;
  int iVar2;
  void *__ptr;
  long lVar3;
  long in_FS_OFFSET;
  undefined8 uVar4;
  undefined4 local_5c;
  int local_58;
  long local_48 [5];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  puts("\nThis is the phase you have been waiting for... one may say it\'s the golden stage!");
  puts(
      "Let\'s switch things up! Numerical inputs map to line numbers in rockyou.txt, and each word is separated by a \'_\' (if the phase\'s solution is 4 5, the flag would be DawgCTF{password_iloveyou})"
      );
  local_5c = 1;
  local_48[0] = 1;
  local_48[1] = 0x7b;
  local_48[2] = 0x3b18;
  local_48[3] = 0x1c640d;
  iVar2 = func4(10) 55;
  uVar4 = 0x10157f;
  __ptr = calloc(4,4) 16;
  getInput(4,param_1,"%d%d%d%d",__ptr,(long)__ptr + 4,(long)__ptr + 8,(long)__ptr + 0xc,uVar4);
  local_58 = 0;
  while (local_58 < 4) {
    lVar1 = local_48[local_58];
    lVar3 = func4(*(undefined4 *)((long)__ptr + (long)local_58 * 4))//compute each int with func4 ;
    if (lVar1 * iVar2 - lVar3 != 0) {
      local_5c = 0;
    }
    local_58 = local_58 + 1;
  }
  free(__ptr);
  if (local_20 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_5c;
}
