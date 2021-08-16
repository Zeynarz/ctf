undefined8 actualBattle(int enemyId){
  long in_FS_OFFSET;
  int userChoice;
  long local_10;
  
  if (*(enemiesList + enemyId * 8) == 0) {
    puts("There\'s no one here to battle ");
  }
  else {
    printf("Starting battle with %s ....\n",enemyName);
    if (0 < enemyHealth) {
      enemyHealth = enemyHealth - *(DAT_00104030 + 8);
    }
    printf("\n[*] Health remaining : %d\n",enemyHealth);
    if (enemyHealth < 0) {
      userChoice = 0;
      printf("You beat \'em!\n1.kill\n2.spare\n>>");
      scanf("%d",&userChoice);
      if (userChoice == 1) {
        puts("killed");
        free(*(enemiesList + enemyId * 8));
        free(**(enemiesList + enemyId * 8));
        *(enemiesList + enemyId * 8) = 0;
        goto LAB_001015d3;
      }
      puts("spared their lives ");
    }
    puts("\nthey aint dead yet !");
  }
LAB_001015d3:
  return 0;
}
