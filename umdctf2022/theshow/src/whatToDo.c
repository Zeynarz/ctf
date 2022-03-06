undefined4 whatToDo(void)
{
  long in_FS_OFFSET;
  int userChoice;
  undefined4 local_14;
  long local_10;
  
  puts("What would you like to do?");
  userChoice = 0;
  local_14 = 0;
  puts("+-------------+");
  puts("|   Actions   |");
  puts("|-------------|");
  puts("| Perform Act |");
  puts("| Switch Act  |");
  puts("| End Show    |");
  puts("+-------------|");
  printf("Action: ");
  __isoc99_scanf("%d",&userChoice);
  if (userChoice == 1){
    (**(code **)(currentAct + 0x60))();

  } else if (userChoice == 2) {
    switchAct();
    puts("I think the current act switched switched. It might appear when we start up again...");

  } else if (userChoice == 3){
    local_14 = 1;
  }

  return local_14;
}
