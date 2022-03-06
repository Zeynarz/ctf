void main(void)

{
  int iVar1;
  
  setbuf((FILE *)stdout,(char *)0x0);
  setbuf((FILE *)stdin,(char *)0x0);
  setbuf((FILE *)stderr,(char *)0x0);
  setup();
  iVar1 = whatToDo();
  if (iVar1 != 0) {
    puts("The show is over, goodbye!");
  }
  return;
}
