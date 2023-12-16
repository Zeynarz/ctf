void chooseJuices(void){
  int local_c;
  
  displayAvailableJuices();
  printf("Enter the number of the chosen juice (1-5): ");
  __isoc99_scanf("%d",&local_c);
  if ((local_c < 1) || (5 < local_c)) {
    puts("Invalid selection. Please try again.");
  }
  else {
    chosenJuice = malloc(0x114);
    if (chosenJuice == (char *)0x0) {
      perror("Error allocating memory");
      exit(1);
    }
    strcpy(chosenJuice,availableJuices + (long)(local_c + -1) * 0x114);
    *(chosenJuice + 0x100) = *(&DAT_00302120 + (long)(local_c + -1) * 0x114);
    strcpy(chosenJuice + 0x104,s_Orange_00302124 + (long)(local_c + -1) * 0x114);
    printf("You chose %s juice.\n",chosenJuice);
  }
  return;
}

void displayAvailableJuices(void){
  int local_c;

  puts("Available Juices:");
  local_c = 0;
  while (local_c < 5) {
    printf("%d. %s\n",(ulong)(local_c + 1),availableJuices + (long)local_c * 0x114);
    local_c = local_c + 1;
  }
  return;
}

void refillJuices(void){
  if (chosenJuice == 0) {
    puts("Please choose a juice first.");
  }
  else {
    printf("Enter the quantity to refill: ");
    __isoc99_scanf("%d",chosenJuice + 0x100);
    puts("Juice refilled!");
  }
  return;
}

void drinkJuices(void){
  if (chosenJuice == (void *)0x0) {
    puts("Please choose a juice first.");
  }
  else {
    puts("Enjoy the refreshing experience of your chosen juice. Cheers! ");
    putchar(10);
    free(chosenJuice);
    chosenJuice = (void *)0x0;
  }
  return;
}


void secretJuice(void){
  // option 1337
  long in_FS_OFFSET;
  char local_118 [264];
  long local_10;

  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  if (chosenJuice == (char *)0x0) {
    puts("Please choose a juice first.");
  } else {
    puts("Let us know what juices you need and we will get back to you!");
    __isoc99_scanf("%256s",local_118);
    printf("Current Juice : ");
    printf(local_118);
    strncpy(chosenJuice,local_118,0xff);
    chosenJuice[0xff] = '\0';
    putchar(10);
  }
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
    __stack_chk_fail();
  }
  return;
}
