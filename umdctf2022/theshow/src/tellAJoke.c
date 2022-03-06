void tellAJoke(void)

{
  int iVar1;
  time_t tVar2;
  
  tVar2 = time((time_t *)0x0);
  srandom((uint)tVar2);
  iVar1 = rand();
  puts("Here we go!");
  puts(*(char **)(jokes + (long)(iVar1 % 3) * 8));
  return;
}
