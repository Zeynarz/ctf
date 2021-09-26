__pid_t wait(void *__stat_loc){
  __pid_t _Var1;
  ulong userLong;
  char userInput [5];
  char local_88 [120];
  
  puts("Press enter to continue");
  getc(stdin);
  printf("Pick a number: ");
  fgets(userInput,5,stdin);
  userLong = strtol(userInput,0x0,10);
  snprintf(local_88,100,"Your magic number is: %%%d$llx\n",userLong & 0xffffffff);
  printf(local_88);
  _Var1 = introduce();
  return _Var1;
}
