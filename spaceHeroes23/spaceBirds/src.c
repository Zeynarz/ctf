undefined8 main(void)

{
  long lVar1;
  long in_FS_OFFSET;
  
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  logo();
  vuln();
  if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}


void vuln(void) {
  long in_FS_OFFSET;
  char local_78 [104];
  long local_10;

  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  puts("Space Birds Arent Real");
  printf("Serial Code: %p\n",rand);
  puts("--------------------------------------------------------------------------------");
  printf("Report updated drone sightings in your area >>> ");
  read(0,local_78,0x6c);
  printf(local_78);
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}
