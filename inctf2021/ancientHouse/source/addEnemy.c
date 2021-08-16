int addEnemy(void)

{
  uint uVar1;
  void *enemyObject;
  long in_FS_OFFSET;
  int size;
  void *enemyName;
  
  if (5 < amountOfEnemies) {
    puts("too many allocations !!");
  }
  else {
    enemyObject = malloc(0x18);
    *(enemiesList + amountOfEnemies * 8) = enemyObject;
    size = 0;
    printf("Enter the size : ");
    scanf("%d",&size);
    if (0x70 < size) {
      puts("Too large ! ");
      exit(1);
    }
    enemyName = malloc(size);
    printf("Enter name : ");
    readInput(enemyName,size);
    **(enemiesList + amountOfEnemies * 8) = enemyName;
    *(*(enemiesList + amountOfEnemies * 8) + 8) = 0x64;
    *(*(enemiesList + amountOfEnemies * 8) + 12) = amountOfEnemies;
    *(*(enemiesList + amountOfEnemies * 8) + 16) = size;
    amountOfEnemies = amountOfEnemies + 1;
  }
  return 0;
}
