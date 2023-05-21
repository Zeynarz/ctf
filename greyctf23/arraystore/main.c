undefined8 main(void)

{
  longlong lVar1;
  longlong lVar2;
  long in_FS_OFFSET;
  longlong arr [100];
  char choice [104];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  setbuf(stdout,(char *)0x0);
  setbuf(stdin,(char *)0x0);
  setbuf(stderr,(char *)0x0);
  puts("Your array has 100 entries");
  do {
    while( true ) {
      printf("Read/Write?: ");
      fgets(choice,100,stdin);
      if (choice[0] == 'R') break;
      if (choice[0] != 'W') {
        puts("Invalid option");
      }
      
      // W:
      printf("Index: ");
      fgets(choice,100,stdin);
      lVar1 = strtoll(choice,0x0,10);
      if (lVar1 < 100) {
        // no negative index check
        printf("Value: ");
        fgets(choice,100,stdin);
        lVar2 = strtoll(choice,(char **)0x0,10);
        arr[lVar1] = lVar2;
      }
      else {
LAB_001011b8:
        puts("Invalid index");
      }
    }

    // R:
    printf("Index: ");
    fgets(choice,100,stdin);
    lVar1 = strtoll(choice,(char **)0x0,10);
    if (99 < lVar1) goto LAB_001011b8;
    printf("Value: %lld\n",arr[lVar1]);
  } while( true );
}

