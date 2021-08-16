undefined8 FUN_00101a09(void)

{
  long in_FS_OFFSET;
  int enemyId1;
  int enemyId2;
  long local_10;
  
  if (mergeTimes == 0) {
    puts("Select 2 enemies to merge ");
    printf("[+] Enemy id 1: ");
    scanf("%d",&enemyId1);
    printf("[+] Enemy id 2: ");
    scanf("%d",&enemyId2);
    if ((((enemyId1 < 0) || (enemyId2 < 0)) || (amountOfEnemies <= enemyId1)) ||
       (amountOfEnemies <= enemyId2)) {
      puts("Invalid operation !");
    }
    else {
      FUN_0010180d(enemyId1,enemyId2,enemyId2);
      mergeTimes = mergeTimes + 1;
    }
  }
  else {
    puts("You get only one chance!");
  }
  return 0;
}
