
undefined8 setup(void)

{
  undefined8 *puVar1;
  long in_FS_OFFSET;
  int local_44;
  char *local_40;
  undefined actName [40];
  long local_10;
  
  local_40 = (char *)0x0;
  local_44 = 0;
  message1 = malloc_set(0x50);
  message2 = malloc_set(0x60);
  message3 = malloc_set(0x80);
  puVar1 = message1;
  puVar1[0] = 0x20656d6f636c6557;
  puVar1[1] = 0x6320656874206f74;
  puVar1[2] = 0x6c63207964656d6f;
  puVar1[3] = 0xa216275;

  puVar1 = message2;
  puVar1[0] = 0x20796c6e6f206557;
  puVar1[1] = 0x6568742065766168;
  puVar1[2] = 0x6f63207473656220;
  puVar1[3] = 0x20736e616964656d;
  puVar1[4] = 0x0000002165726568;

  puVar1 = message3;
  puVar[0] = 0x6820657361656c50;
  puVar1[1] = 0x7320737520706c65;
  puVar1[2] = 0x6f66207075207465;
  puVar1[3] = 0x612072756f792072;
  *(undefined4 *)(puVar1 + 4) = 0xa7463;

  printf("%s",message1);
  printf("%s",message2);
  printf("%s",message3);

  puts("What is the name of your act?");
  __isoc99_scanf("%s",actName);
  mainAct = malloc_set(0x68);

  __strncpy_sse2_unaligned(mainAct,actName,0x20);
  local_40 = crypt("Main_Act_Is_The_Best",salt);

  __strncpy_sse2_unaligned(mainAct + 0x20,local_40,0x40);
  puts("Your act code is: Main_Act_Is_The_Best");
  *(mainAct + 0x60) = tellAJoke;
  currentAct = mainAct;
  free(message1);
  free(message3);

  puts("How long do you want the show description to be?");
  __isoc99_scanf("%d",&local_44);
  showDescription = malloc_set(local_44 + 8);

  puts("Describe the show for us:");
  getchar();
  fgets(showDescription,500,stdin);
  actList._0_8_ = mainAct;
  return 0;
}
