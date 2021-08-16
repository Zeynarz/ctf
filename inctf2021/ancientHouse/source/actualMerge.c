undefined8 FUN_0010180d(int id1,int id2)

{
  int enemySize1;
  int enemySize2;
  void **enemyObject1;
  void *mergedEnemyName;
  
  enemySize1 = *(*(enemiesList + id1 * 8) + 0x10);
  enemySize2 = *(*(enemiesList + id2 * 8) + 0x10);
  if (((id1 != id2) && (enemySize1 == enemySize2)) && (enemySize2 + enemySize1 < 0x60)) {
    enemyObject1 = *(enemiesList + id1 * 8);
    mergedEnemyName = realloc(enemyName,(enemySize2 + enemySize1));
    *enemyObject1 = mergedEnemyName;
    *(enemyObject1 + 0x10) = enemySize2 + enemySize1;
    *(enemyObject1 + 8) = enemyHealth1 + enemyHealth2;

    mergeName(enemyName1,enemyName2,mergedEnemySize);
    free(enemyName2);
    free(enemyObject2);
    *(enemiesList + id2 * 8) = 0;
    return 0;
  }
  puts("Dont try anything funny ");
  exit(1);
}
//*(enemiesList + id1 * 8) = enemyObject
//*(*(enemiesList + id1 * 8) + 8) = enemyHealth
//**(enemiesList + id1 * 8) = enemyName 
