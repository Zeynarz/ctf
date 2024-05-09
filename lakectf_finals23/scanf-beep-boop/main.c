void main(void){
  long lVar1;
  
  puts(&DAT_004020b8);
  puts("BINARY GO BRRRRRRRRRRRRRRRRRR");
  setup_buffers();
  while( true ) {
    menu();
    if (tries == '\0') break;
    lVar1 = get_number("choice");
    if (lVar1 != 0) break;
    beep_boop();
    tries = tries + -1;
  }
  exit(0);
}

void setup_buffers(void){
  stdin_buffer = (char *)mmap((void *)0x13371337000,0x42,3,0x32,-1,0);
  if (stdin_buffer == (char *)0xffffffffffffffff) {
    printf("mmap error. exiting.");
    exit(1);
  }
  setvbuf(stdin,stdin_buffer,1,0x42);
  setbuf(stdout,(char *)0x0);
  setbuf(stderr,(char *)0x0);
  return;
}

void beep_boop(void){
  int iVar1;
  undefined *dst;
  ulong uVar2;

  dst = (undefined *)get_number("dst address");
  uVar2 = get_number("src idx");
  iVar1 = check_valid(dst,&exe_path,&rw_flags,&exe_path);
  if ((iVar1 == 0) || (65 < uVar2)) { // negative numbers work somehow
    printf("invalid : %zx, %zx.\n",dst,uVar2);
  }
  else {
    puts("ok !");
    *dst = *(undefined *)(uVar2 + stdin_buffer);
  }
  return;
}

undefined8 check_valid(ulong param_1,char *param_2,char *param_3){
  char *pcVar1;
  __ssize_t _Var2;
  undefined8 uVar3;
  long in_FS_OFFSET;
  char *local_38;
  size_t local_30;
  ulong local_28;
  ulong local_20;
  FILE *local_18;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_18 = fopen("/proc/self/maps","r");
  local_38 = (char *)0x0;
  local_30 = 0;
  local_28 = 0;
  local_20 = 0;
  do {
    do {
      do {
        _Var2 = getline(&local_38,&local_30,local_18);
        if (_Var2 == -1) {
          free(local_38);
          fclose(local_18);
          uVar3 = 0;
          goto LAB_004014f0;
        }
        pcVar1 = strstr(local_38,param_3);
      } while (pcVar1 == (char *)0x0);
      pcVar1 = strstr(local_38,param_2);
    } while (pcVar1 == (char *)0x0);
    __isoc99_sscanf(local_38,"%zx-%zx",&local_28,&local_20);
    printf("Checking that %zx is in %zx - %zx...\n",param_1,local_28,local_20);
  } while ((param_1 < local_28) || (local_20 <= param_1));
  uVar3 = 1;
LAB_004014f0:
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
    __stack_chk_fail();
  }
  return uVar3;
}

