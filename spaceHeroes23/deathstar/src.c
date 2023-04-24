void main(void)

{
  code *local_20;
  int local_14;
  code *local_10;
  
  while (true) {
    while( true ) {
      while (3 < local_14); {
        while( true ) {
          // wrong option input again
          print_terminal();
          __isoc99_scanf("%d",&local_14);
          if (local_14 != 3) break;
          (*local_10)(); // option 3 execute the code
        }
      } 
      if (local_14 == 1) break;
      if (local_14 == 2) {
        // option 2 goes here
        printf("Target Coordinates => %ld\n",local_10);
      }
    }

    // option 1 goes here
    print_choice();
    __isoc99_scanf("%ld",&local_20);
    switch(local_20) {
    default:
      local_10 = local_20;
      break;
    case (code *)0x1:
      local_10 = alderaan;
      break;
    case (code *)0x2:
      local_10 = yavin_4;
      break;
    case (code *)0x3:
      local_10 = dantoine;
      break;
    case (code *)0x4:
      local_10 = tatooine;
      break;
    case (code *)0x5:
      local_10 = dagobah;
      break;
    case (code *)0x6:
      local_10 = hoth;
      break;
    case (code *)0x7:
      local_10 = bespin;
    }
  }
}

