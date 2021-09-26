void get_num_bytes(void)

{
  ulong uVar1;
  char userInput [13];
  
  printf("How many bytes do you want to read (max 256)? ");
  fgets(userInput,5,stdin);
  uVar1 = strtol(userInput,0x0,10);
  if (uVar1 < 0x101) {
    echo(uVar1 & 0xffffffff);
    return;
  }
  puts("Don\'t break the rules!");
  return;
}
