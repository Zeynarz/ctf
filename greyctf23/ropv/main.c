undefined8 main(void){
  char acStack32 [8];
  longlong local_18;
  
  local_18 = __stack_chk_guard;
  setbuf((FILE *)stdout,(char *)0x0);
  setbuf((FILE *)stdin,(char *)0x0);
  setbuf((FILE *)stderr,(char *)0x0);
  printf("Echo server: ");
  read(0,acStack32,0x400);
  printf(acStack32);
  puts("");
  printf("Echo server: ");
  read(0,acStack32,0x400);
  printf(acStack32);
  puts("");
  if (local_18 != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
    gp = (undefined1 *)((longlong)static_slotinfo + 0x3c8);
  }
  gp = (undefined1 *)((longlong)static_slotinfo + 0x3c8);
  return 0;
}
