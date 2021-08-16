char * FUN_0010178f(char *enemyName1,long enemyName2,ulong mergedSize)
{
  size_t nameLength1;
  ulong local_18;
  
  nameLength1 = strlen(enemyName1);
  local_18 = 0;
  while (local_18 < mergedSize) {
    enemyName1[nameLength1 + local_18] = *(local_18 + enemyName2);
    local_18 = local_18 + 1;
  }
  enemyName1[nameLength1 + local_18] = '\0';
  return enemyName1;
}
