void main(void)
{
  void **heapPtr1;
  void *heapPtr2;
  long in_FS_OFFSET;
  int userChoice;
  code **heapPtr3;
  undefined8 local_20;
  
  setup();
  heapPtr1  = malloc(0x10);
  namePtrPtr = heapPtr1;
  heapPtr2 = malloc(0x40);
  *heapPtr1 = heapPtr2;
  printf("Who dares to enter these hallowed halls!! : ");
  readInput(*namePtrPtr,0x40);
  *(namePtrPtr + 1) = 0xf;
  *(namePtrPtr + 0xc) = 100;
  heapPtr3 = malloc(0x50);
  *heapPtr3 = FUN_00101b82;
  puts("banner here");
  while( true ) {
    menu();
    scanf("%d",&userChoice);
    if (3 < userChoice || local_2c < 0) break;
    if (userChoice == 1) 
        addEnemy();

    else if (userChoice == 2)
        battle();

    else if (userChoice == 3)
        merge();
  }
  //execute code here
  (**heapPtr3)(heapPtr3[1]);
  exit(1);
}
