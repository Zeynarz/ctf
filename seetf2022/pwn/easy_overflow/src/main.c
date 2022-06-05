undefined8 main(void)

{
  char local_28 [32];
  
  setbuf(stdout,(char *)0x0);
  setbuf(stdin,(char *)0x0);
  puts("I will let you  overflow me.");
  vuln();
  puts("I will give you one more chance.");
  fgets(local_28,8,stdin);
  puts(local_28);
  return 0;
}
