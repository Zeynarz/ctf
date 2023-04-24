undefined8 main(void) {
  time_t tVar1;
  int secondColumn;
  int secondRow;
  int firstColumn;
  int firstRow;
  char local_59;
  undefined local_58 [16];
  undefined local_48 [16];
  char local_38 [40];
  int local_10;
  int local_c;
  
  local_59 = 'F';
  firstRow = 0;
  firstColumn = 0;
  secondRow = 0;
  secondColumn = 0;
  tVar1 = time(0x0);
  srand(tVar1);
  local_c = rand();
  puts("  ___________________        ____....-----....____");
  puts(" (________________LL_)   ==============================");
  puts("     ______\\   \\_______.--\\\'.  `---..._____...---\'");
  puts("     `-------..__            ` ,/");
  puts("                 `-._ -  -  - |");
  puts("                     `-------\'");
  puts("Welcome to Space Memory Captain!");
  puts("We\'ve designed this game to keep you sharp while in space!");
  printf((local_c & 0x7fffffffffffffff),0x7fffffffffffffff,
         "You\'ve been in space for %d\n");
  fill_blank_board(local_48);
  fill_board(local_58);
  puts("Here\'s the board:");
  print_board(local_48);
  if (board_checker_bool == 1) {
    local_48[(long)firstColumn + (long)firstRow * 4] = 0x24;
    local_48[(long)secondColumn + (long)secondRow * 4] = 0x24;
    board_checker_bool = 0;
  }
  printf("Choose an option: \n(F) Find a match \n(Q) Quit \nChoice: ");
  __isoc99_scanf("%c",&local_59);
  if (local_59 == 'Q') {
    exit(0);
  }
  printf("Pick first card (row, column): ");
  __isoc99_scanf("%d,%d",&firstRow,&firstColumn);
  printf("Pick second card (row, column): ");
  __isoc99_scanf("%d,%d",&secondRow,&secondColumn);
  if ((((firstRow == 0x539) && (secondRow == 0x7a69)) && (firstColumn == 0x7a69)) && (secondColumn == 0x539)
     ) {
    printf("It seems like your a hacker! Enjoy this nice treat: %p\n",get_long_long);
    print_board(local_58);
    printf("Can you win this turn now?\n >>> ");
    do {
      local_10 = getchar();
      if (local_10 == 10) break;
    } while (local_10 != -1);
    gets(local_38);
  }
  printf("Your total points: %d. Goodbye!\n",user_points);
  return 0;
}

void fill_blank_board(long param_1)

{
  int local_10;
  int local_c;

  local_c = 0;
  while (local_c < 4) {
    local_10 = 0;
    while (local_10 < 4) {
      *(undefined *)((long)local_c * 4 + param_1 + (long)local_10) = 0x24;
      local_10 = local_10 + 1;
    }
    local_c = local_c + 1;
  }
  return;
}


void fill_board(long param_1)

{
  int iVar1;
  time_t tVar2;
  int aiStack136 [8];
  int aiStack104 [11];
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  tVar2 = time((time_t *)0x0);
  srand((uint)tVar2);
  local_c = 0;
  while (local_c < 8) {
    iVar1 = rand();
    aiStack136[local_c] = iVar1 % 0x1a;
    local_c = local_c + 1;
  }
  local_10 = 0;
  while (local_10 < 8) {
    local_14 = 0;
    while (local_14 < 8) {
      if ((aiStack136[local_10] == aiStack136[local_14]) && (local_10 != local_14)) {
        iVar1 = rand();
        aiStack136[local_14] = iVar1 % 0x1a;
      }
      local_14 = local_14 + 1;
    }
    local_10 = local_10 + 1;
  }
  local_18 = 0;
  while (local_18 < 8) {
    local_1c = 0;
    while (local_1c < 8) {
      if ((aiStack136[local_18] == aiStack136[local_1c]) && (local_18 != local_1c)) {
        iVar1 = rand();
        aiStack136[local_1c] = iVar1 % 0x1a;
      }
      local_1c = local_1c + 1;
    }
    local_18 = local_18 + 1;
  }
  local_20 = 0;
  local_24 = 8;
  while (local_24 < 0x10) {
    aiStack136[local_24] = aiStack136[local_20];
    local_20 = local_20 + 1;
    local_24 = local_24 + 1;
  }
  local_38 = 0;
  local_28 = 0xf;
  while (0 < local_28) {
    local_3c = rand();
    local_3c = local_3c % (local_28 + 1);
    local_38 = aiStack136[local_3c];
    aiStack136[local_3c] = aiStack136[local_28];
    aiStack136[local_28] = local_38;
    local_28 = local_28 + -1;
  }
  local_2c = 0xf;
  local_30 = 0;
  while (local_30 < 4) {
    local_34 = 0;
    while (local_34 < 4) {
      *(char *)((long)local_30 * 4 + param_1 + (long)local_34) = (char)aiStack136[local_2c] + 'A';
      local_2c = local_2c + -1;
      local_34 = local_34 + 1;
    }
    local_30 = local_30 + 1;
  }
  return;
}

void print_board(long param_1)

{
  int local_10;
  uint local_c;

  puts("    0   1   2   3");
  local_c = 0;
  while ((int)local_c < 4) {
    printf("%d ",(ulong)local_c);
    local_10 = 0;
    while (local_10 < 4) {
      printf("| %c ",(ulong)(uint)(int)*(char *)((long)(int)local_c * 4 + param_1 + (long)local_10))
      ;
      local_10 = local_10 + 1;
    }
    puts("\n-----------------");
    local_c = local_c + 1;
  }
  return;
}

