undefined8 main(void)

{
  int iVar1;
  int iVar2;
  size_t sVar3;
  char *__s1;
  char *__s1_00;
  char *in_RCX;
  char *pcVar4;
  int extraout_EDX;
  int extraout_EDX_00;
  int extraout_EDX_01;
  int extraout_EDX_02;
  ulong extraout_RDX;
  ulong uVar5;
  undefined8 *puVar6;
  char *pcVar7;
  int in_R8D;
  int in_R9D;
  byte thirdNineBytes [64];
  undefined8 local_b8;
  undefined8 local_b0;
  undefined2 local_a8;
  undefined8 local_98;
  undefined8 local_90;
  undefined2 local_88;
  byte secondNineBytes [9];
  byte firstNineBytes [9];
  byte userInput [9];
  byte abStack95 [9];
  byte abStack86 [10];
  undefined4 local_4c;
  char *local_48;
  char *local_40;
  char *local_38;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int i;
  int local_c;
  
  logo();
  local_38 = "\nIf you are a true Guardian you know the password!!\npassword >>> ";
  slow_print("\nIf you are a true Guardian you know the password!!\npassword >>> ");
  local_40 = "Welcome aboard Guardian, here is your reward for saving our galaxy flag :  ";
  local_48 = 
  "Well!!! you are not a True Guardian.\nAs I said earlier only a true Guardian knows the password!!!\n \nStar Lord will lead you to the exit!!!!!!!!"
  ;
  __isoc99_scanf("%s",userInput);
  local_c = 0;
  i = 0;
  local_14 = 9;
  local_18 = 0x12;
  local_1c = 0;
  local_20 = 0;
  local_24 = 0;
  sVar3 = strlen((char *)userInput);
  if (sVar3 != 0x1b) {
    slow_print(local_48);
    return 0;
  }
  
  // password is 27 bytes long

  i = 0;
  while (i < 9) {
    firstNineBytes[local_c] = userInput[i];
    local_c = local_c + 1;
    i = i + 1;
  }
  
  // first 9 bytes are stored in firstNineBytes 

  local_28 = 0;
  local_2c = 0;
  local_98 = 0;
  local_90 = 0;
  local_88 = 0;
  local_b8 = 0;
  local_b0 = 0;
  local_a8 = 0;
  local_14 = 9;
  while (local_14 < 0x12) {
    secondNineBytes[local_28] = userInput[local_14];
    local_28 = local_28 + 1;
    local_14 = local_14 + 1;
  }

  puVar6 = &local_98;
  atox(secondNineBytes); // turn to hex
  local_2c = 0;
  uVar5 = extraout_RDX;
  while (local_2c < 9) {
    uVar5 =*(&local_98 + local_2c);
    *(&local_b8 + local_2c) = *(&local_98 + local_2c);
    local_2c = local_2c + 1;
  }
  local_30 = 0;
  local_4c = 0;
  local_18 = 0x12;
  while (local_18 < 0x1b) {
    uVar5 = (ulong)userInput[local_18];
    thirdNineBytes[local_30] = userInput[local_18];
    local_30 = local_30 + 1;
    local_18 = local_18 + 1;
  }
  r(firstNineBytes);
  r(thirdNineBytes);
  r(firstNineBytes);
  iVar1 = strncmp(__s1,"od_pbw1gu",9);
  if (iVar1 == 0) {
    local_1c = 1;
  }
  pcVar4 = "5F31735F6E30745F74";
  pcVar7 = "5F31735F6E30745F74";
  iVar2 = strncmp(&local_b8,"5F31735F6E30745F74",0x12);
  iVar1 = extraout_EDX_01;
  if (iVar2 != 0) {
    pcVar4 = "5F31735F6E30745F74";
    pcVar7 = "5F31735F6E30745F74";
    iVar2 = strncmp((char *)&local_98,"5F31735F6E30745F74",0x12);
    iVar1 = extraout_EDX_02;
    if (iVar2 != 0) goto LAB_00101864;
  }
  local_20 = 1;
LAB_00101864:
  r(thirdNineBytes,pcVar7,iVar1,pcVar4,in_R8D,in_R9D);
  iVar1 = strncmp(__s1_00,"d/[h-i-py",9);
  if (iVar1 == 0) {
    local_24 = 1;
  }
  if (((local_1c == 1) && (local_20 == 1)) && (local_24 == 1)) {
    slow_print(local_40);
    printf("%s",userInput);
  }
  else {
    slow_print(local_48);
  }
  return 0;
}

void r(void *param_1,void *param_2,int param_3,char *param_4,int param_5,int param_6) {
  size_t __size;
  void *pvVar1;
  int local_c;

  __size = strlen((char *)param_1);
  pvVar1 = malloc(__size);
  local_c = 0;
  while (local_c < 9) {
    *(pvVar1 + local_c) = *(param_1 + local_c) - 4;
    local_c = local_c + 1;
  }
  return;
}

void atox(long param_1,long param_2){
  int local_10;
  int local_c;

  local_10 = 0;
  local_c = 0;
  while (local_c < 9) {
    sprintf((local_10 + param_2),"%02X",*(param_1 + local_c));
    local_10 = local_10 + 2;
    local_c = local_c + 1;
  }
  *(undefined *)(param_2 + local_10) = 0;
  return;
}
