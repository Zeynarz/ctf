void vuln(void)

{
  long in_stack_00000000;
  char local_28 [32];
  
  gets(local_28);
  if (in_stack_00000000 == 0x401212) {
    puts("Good  boi\n");
    return;
  }
  puts("Naughty Boi\n");
  exit(-1);
}

