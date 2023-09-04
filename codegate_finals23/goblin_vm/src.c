void instr1(void){
  room = (room - 8);
  *room = reg;
  return;
}

void instr2(void){
  reg = *room; // qword
  room = room + 1; // ptr addition, so actually + 8
  return;
}

void instr3(void){
  reg = reg + 1; // actually add 1
  return;
}

void instr4(void){
  reg = reg - 1;
  return;
}

void instr5(void){
  // 5 123
  // reg += 123
  __nptr = strtok(0x0," ");
  lVar1 = atoll(__nptr);

  reg = reg + lVar1;
  return;
}

void instr6(void){
  __nptr = strtok((char *)0x0," ");
  lVar1 = atoll(__nptr);
  reg = reg - lVar1;
  return;
}

void instr7(void){
  // 7 123
  // reg = 123
  char *__nptr;

  __nptr = strtok((char *)0x0," ");
  reg = atoll(__nptr);
  return;
}

void instr8(void){
  // 8 123
  // room += 123
  __nptr = strtok((char *)0x0," ");
  lVar1 = atoll(__nptr);

  room = lVar1 + room;
  return;
}


void instr9(void){
  __nptr = strtok((char *)0x0," ");
  lVar1 = atoll(__nptr);

  room = room - lVar1;
  return;
}


void instr10(int *param_1,int *param_2){
  // a leak
  // they set it to 1, but technically can get unlimited leaks
  // using the arbitary write primitives
  if (((DAT_00104010 == 1) && (*param_1 == 1)) && (*param_2 == 1)) {
    printf("rax: %ld\n",reg);
    DAT_00104010 = 0;
    *param_1 = 0;
    *param_2 = 0;
  }
  return;
}

