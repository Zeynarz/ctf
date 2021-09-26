void game(void){
  int iVar1;
  FILE *__stream;
  long in_FS_OFFSET;
  int local_14;
  long local_10;
  
  __stream = fopen(RANDBUF,"rb");
  fread(&local_14,1,4,__stream);
  printf("guess: ");
  iVar1 = get_num();
  if (iVar1 == local_14) {
    system("/bin/sh");
  }
}
