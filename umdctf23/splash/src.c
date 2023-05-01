undefined8 main(void) {
  int iVar1;
  char *pcVar2;
  long lVar3;
  undefined8 *puVar4;
  long in_FS_OFFSET;
  uint arceusHealth;
  uint splashPp;
  undefined8 choice;
  undefined8 local_410;
  undefined8 local_408 [127];
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  choice = 0;
  local_410 = 0;
  lVar3 = 0x7e;
  // just makes everything in choice null
  puVar4 = local_408;
  while (lVar3 != 0) {
    lVar3 = lVar3  - 1;
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *(undefined *)puVar4 = 0;
  arceusHealth = 0x202;
  splashPp = 0x7ffffffe;
  setvbuf(stdout,(char *)0x0,2,0);
  puts("You are challenged by ESIDDALI!");
  puts("ESIDDALI sent out MAGIKARP!");
  puts("Go! ARCEUS!");
  puts("What will you do? (Enter a number)");
  puts("0. CHECK BATTLE STATUS");
  puts("1. FIGHT");
  puts("2. BAG");
  puts("3. RUN");
  puts("4. POKEMON");
  putchar(10);
  while (true) {
    pcVar2 = fgets(&choice,0x401,stdin);
    if (pcVar2 == 0x0) {
LAB_0010183a:
      if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
        __stack_chk_fail();
      }
      return 0;
    }
    iVar1 = strcmp((char *)&choice,"0\n");
    if (iVar1 == 0) {
      // choice 0
      printf("MAGIKARP has %d health. Reduce this to zero to win.\n",1);
      printf("ARCEUS has %d health. If this is reduced to zero, you lose.\n",(ulong)arceusHealth);
      printf("ARCEUS only knows SPLASH. ARCEUS\'s SPLASH has %d PP. If SPLASH has zero PP, ARCEUS will STRUGGLE.\n"
             ,(ulong)splashPp);
      puts("Your bag is full of PP UP. Use them to increase the PP associated with ARCEUS\'s SPLASH.");
      puts("You cannot run from a trainer battle.");
      puts("You only have ARCEUS in your party of POKEMON");
    }
    else {
      iVar1 = strcmp((char *)&choice,"1\n");
      if (iVar1 == 0) {
        // choice 1
        if (splashPp < 1) {
          puts("ARCEUS has no moves left!");
          puts("ARCEUS used STRUGGLE!\nARCEUS is hit with recoil!");
          if (arceusHealth < 0x81) {
            puts("ARCEUS fainted!");
            puts("You have ran out of usable POKEMON!");
            puts("Unlucky!1!");
          }
          else {
            puts("Foe MAGIKARP fainted!");
            puts("You defeated ESIDDALI!");
            puts(
                "Uh.... I wasted all my money on boba and Taco Bell, please accept this flag instead."
                );
            FUN_00101229();
          }
          goto LAB_0010183a;
        }
        printf("ARCEUS used SPLASH!\nBut nothing happened!");
        puts("The foe\'s MAGIKARP used JUDGEMENT!");
        arceusHealth = arceusHealth - 0x80;
        if ((int)arceusHealth < 1) {
          puts("ARCEUS fainted!");
          puts("You have ran out of usable POKEMON!");
          puts("Unlucky!1!");
          goto LAB_0010183a;
        }
        splashPp = splashPp - 1;
        printf("(ARCEUS has %d health now)\n",(ulong)arceusHealth);
        puts("(MAGIKARP\'s health is unchanged)");
        printf("(ARCEUS\'s SPLASH has %d PP now)\n",(ulong)splashPp);
      }
      else {
        iVar1 = strcmp(&choice,"2\n");
        if (iVar1 == 0) {
          puts("You dumped PP UP on ARCEUS!");
          splashPp = splashPp + 1;
          printf("(ARCEUS\'s SPLASH has %d PP now)\n",(ulong)splashPp);
          puts("The foe\'s MAGIKARP used JUDGEMENT!");
          arceusHealth = arceusHealth - 0x80;
          if ((int)arceusHealth < 1) {
            puts("ARCEUS fainted!");
            puts("You have ran out of usable POKEMON!");
            puts("Unlucky!1!");
            goto LAB_0010183a;
          }
          printf("(ARCEUS has %d health now)\n",(ulong)arceusHealth);
          puts("(MAGIKARP\'s health is unchanged)");
        }
        else {
          iVar1 = strcmp((char *)&choice,"3\n");
          if (iVar1 == 0) {
            puts("You can\'t run from a trainer battle, coward!");
            puts("The foe\'s MAGIKARP used JUDGEMENT!");
            arceusHealth = arceusHealth - 0x80;
            if ((int)arceusHealth < 1) {
              puts("ARCEUS fainted!");
              puts("You have ran out of usable POKEMON!");
              puts("Unlucky!1!");
              goto LAB_0010183a;
            }
            printf("(ARCEUS has %d health now)\n",(ulong)arceusHealth);
            puts("(MAGIKARP\'s health is unchanged)");
          }
          else {
            iVar1 = strcmp((char *)&choice,"4\n");
            if (iVar1 == 0) {
              puts("You only have ARCEUS in your party. There\'s no one to switch out with!");
            }
            else {
              puts("Invalid.");
            }
          }
        }
      }
    }
    puts("\nWhat will you do? (Enter a number)");
    puts("0. CHECK BATTLE STATUS");
    puts("1. FIGHT");
    puts("2. BAG");
    puts("3. RUN");
    puts("4. POKEMON");
    putchar(10);
  }
}
