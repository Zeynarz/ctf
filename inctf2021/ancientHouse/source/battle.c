undefined8 FUN_00101b0d(void)

{
  long in_FS_OFFSET;
  undefined4 enemyId;
  long local_10;
  
  puts("Battle ");
  printf("Enter enemy id : ");
  scanf("%d",&enemyId);
  actualBattle(enemyId);
  return 0;
}
