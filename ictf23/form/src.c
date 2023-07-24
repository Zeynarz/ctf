void main(void){
  size_t sVar1;
  long in_FS_OFFSET;
  char *local_28;
  char **local_20;
  FILE *local_18;
  undefined8 local_10;
  
  local_10 = *(undefined8 *)(in_FS_OFFSET + 0x28);

  local_20 = malloc(0x20);
  local_28 = malloc(0x20);
  setbuf(stdin,(char *)0x0);
  setbuf(stdout,(char *)0x0);

  local_18 = fopen("flag.txt","r");
  fgets(local_20,0x20,local_18);
  fgets(local_28,0x20,stdin);
  local_20 = &local_28; // changed the pointer on the stack that points to the flag
  sVar1 = strlen(local_20); // strlen(&pointer), so it will always return 6
  if (sVar1 < 0x18) {
    printf(local_28);
  }
  _exit(0);
}

