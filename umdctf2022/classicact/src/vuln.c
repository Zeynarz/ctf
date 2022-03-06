bool vuln(void) {

  int iVar1;
  long in_FS_OFFSET;
  char local_68 [16];
  char local_58 [72];
  long local_10;
  
  puts("Please enter your name!");
  gets(local_68);
  puts("Hello:");
  printf(local_68);
  putchar(10);
  puts("What would you like to do today?");
  gets(local_58);
  iVar1 = strncmp(local_58,"Play in UMDCTF!",0xf);
  if (iVar1 != 0) {
    puts("Good luck doing that!");
  }
  else {
    puts("You have come to the right place!");
  }

  return iVar1 != 0;
}
