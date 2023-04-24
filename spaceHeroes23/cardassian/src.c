void main(void) {
  long in_FS_OFFSET;
  undefined4 local_78;
  int local_74;
  char *local_70;
  undefined local_68 [88];
  undefined8 local_10;
  
  local_10 = *(undefined8 *)(in_FS_OFFSET + 0x28);
  print_art();
  putchar(0xa);
  local_70 = malloc(0x40); // this is just to get a ptr variable
  local_74 = getpagesize();
  posix_memalign(&local_70,(long)local_74,(long)local_74); // this allocates 0x1000 bytes (on the heap)
  mprotect(local_70,(long)local_74,7); // a page of the heap is now rwx 
  // posix_memalign wrote into local_70 the address of the rwx region (the allocated chunk region)
  // posix_memalign essentially : malloc(0x1000), then write the chunk addr into local_70
  printf("Please enter your name and rank >>> ");
  fgets(local_70,0x40,stdin);
  printf("\nWelcome back, %s\n",local_70);
  do {
    print_menu();
    __isoc99_scanf(&DAT_00102ee3,&local_78);
    getchar();
    performAction(local_78,local_68,local_68);
  } while( true );
}

void performAction(int param_1,long param_2) {
  long in_FS_OFFSET;
  uint local_1c;
  int i;
  int j;
  long local_10;

  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  putchar(10);

  if (param_1 == 1) {
    i = 0;
    while (i < 10) {
      printf("Target %2d >>> ",(i + 1));
      __isoc99_scanf("%ld",(param_1 + i*8));
      i = i + 1;
    }
    goto LAB_001017eb;

  } else if (param_1 == 2) {
    j = 0;
    while (j < 10) {
      printf("Target %2d: %ld\n",(j + 1U),*(param_2 + (long)j * 8));
      j = j + 1;
    }
    goto LAB_001017eb;

  } else if (param_1 == 3) {
    printf("Which target will you modify? >>> ");
    __isoc99_scanf("%d",&local_1c);
    printf("New coordinates for Target %d >>> ");
    __isoc99_scanf(&DAT_00102eab,param_2 + local_1c * 8,); // no boundary check
    goto LAB_001017eb;

  } else if (param_1 == 4) {
    printf("Which target will you list? >>> ");
    __isoc99_scanf("%d",&local_1c);
    printf("Target %d is at these coordinates: %ld\n",local_1c,
           *(undefined8 *)(param_2 + (long)(int)local_1c * 8));
    goto LAB_001017eb;
  }
  puts("Invalid choice");

LAB_001017eb:
  putchar(10);
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
  __stack_chk_fail();
}
