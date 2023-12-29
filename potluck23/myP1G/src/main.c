undefined8 main(EVP_PKEY_CTX *param_1,long param_2){
  int iVar1;
  undefined8 uVar2;
  void *__buf;
  int fd;
  
  init(param_1);
  if ((int)param_1 == 2) {
    // can use stdout to input the vm code
    iVar1 = strcmp(*(param_2 + 8),"stdout");
    if (iVar1 == 0) {
      fd = 0;
    }
    else {
      fd = open(*(char **)(param_2 + 8),0);
      if (fd == -1) {
        write(1,"Error: Open failed\n",0x14);
        return 0xffffffff;
      }
    }
    __buf = calloc(1,0x20000);
    read(fd,__buf,0x20000);
    parser(__buf);
    vmRun();
    uVar2 = 1;
  }
  else {
    write(1,"Usage: ./myP1G code.txt\n",0x18);
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

undefined8 parser(char *param_1){
  int iVar1;
  void *pvVar2;
  long in_FS_OFFSET;
  char *local_68;
  char *local_60;
  char *local_58;
  char *p1;
  char *p3;
  char *p4;
  char *p2;
  char *local_30;
  char *local_28;
  long local_20;
  local_20 = *(long *)(in_FS_OFFSET + 0x28);

  // get newline in string, so meaning there are still lines
  local_58 = strtok_r(param_1,"\n",&local_68);
  while (local_58 != (char *)0x0) {
    p1 = strtok_r(local_58," ",&local_60);
    p2 = strtok_r(0x0,", ",&local_60);
    p3 = strtok_r(0x0,", ",&local_60);

    local_30 = p3;
    p4 = strtok_r(0x0,", ",&local_60);
    local_28 = p4;
    iVar1 = strcmp(p1,"thread");
    if (iVar1 == 0) {
      if (mcode_count == 4) {
        write(1,"Error: Too many thread\n",0x17);
        err();
      }
      iVar1 = mcode_count + 1;
      mcode_count++;
      pvVar2 = calloc(1,0x10000);
      *(mcode + iVar1 * 8) = pvVar2;
    } else {
      if (mcode_count == -1) {
        // mcode_count starts off at -1
        write(1,"Error: There is no thread\n",0x1a);
        err();
      } else {
        generate_mcode(p1,p2,p3,p4);
      }
    }
    local_58 = strtok_r((char *)0x0,"\n",&local_68);
  }
  return 0;
}
