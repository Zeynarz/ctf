int init(EVP_PKEY_CTX *ctx){
  setvbuf(stdin,(char *)0x0,2,0);
  setvbuf(stdout,(char *)0x0,2,0);
  setvbuf(stderr,(char *)0x0,2,0);
  pagesize = sysconf(0x1e);
  return 0x1040f0;
}

void allocate(void){
  undefined4 *__s;

  __s = (undefined4 *)malloc(pagesize);
  memset(__s,0,pagesize);
  *__s = 1;
  createfd(__s);
  return;
}

int createfd(undefined8 param_1){
  int idx;

  idx = 0;
  while( true ) {
    if (9 < idx) {
      return -1;
    }
    if (*(fds + idx * 8) == 0) break; // fds is a global variable
    idx = idx + 1;
  }
  *(fds + idx * 8) = param_1;
  return idx;
}

undefined8 insert(uint param_1,void *param_2,uint param_3){
  undefined8 uVar1;

  if (*(long *)(fds + (ulong)param_1 * 8) == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    if (pagesize - 4 < param_3) {
      uVar1 = 0xffffffff;
    }
    else {
      memcpy((*(fds + param_1 * 8) + 4),param_2,param_3);
      uVar1 = 0;
    }
  }
  return uVar1;
}

int fd_mprotect(int param_1,int param_2){
  undefined4 *chunkPtr;
  int iVar2;

  chunkPtr = *(fds + (long)param_1 * 8);
  if (chunkPtr == (undefined4 *)0x0) {
    iVar2 = -1;
  }
  else {
    if (param_2 == 1) {
      iVar2 = mprotect((chunkPtr & -pagesize),pagesize,3);
      *chunkPtr = 1;
    }
    else {
      if (param_2 == 2) {
        iVar2 = mprotect((void *)((ulong)chunkPtr & -pagesize),pagesize * 2,7);
        // makes it executable?
        *chunkPtr = 2;
      }
      else {
        iVar2 = -1;
      }
    }
  }
  return iVar2;
}

undefined8 execute(int param_1,undefined8 param_2){
  int *piVar1;
  undefined8 uVar2;

  piVar1 = *(int **)(fds + (long)param_1 * 8);
  if (piVar1 == (int *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    if (*piVar1 == 2) {
      // execute shellcode starting from second byte
      (*(piVar1 + 1))(param_1,param_2,piVar1 + 1);
      uVar2 = 0;
    }
    else {
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

undefined8 delete(uint param_1){
  int *__ptr;
  undefined8 uVar1;

  __ptr = *(int **)(fds + (ulong)param_1 * 8);
  if (__ptr == (int *)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    if (*__ptr != 1) {
      fd_mprotect(param_1,2);
    }
    free(__ptr);
    *(undefined8 *)(fds + (ulong)param_1 * 8) = 0;
    uVar1 = 0;
  }
  return uVar1;
}
