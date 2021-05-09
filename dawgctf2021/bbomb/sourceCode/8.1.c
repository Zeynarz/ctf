char * func8_1(char param_1,char *param_2)

{
  undefined8 uVar1;
  
  if (param_2 == 0x0) {
    param_2 = malloc(0x18);
    *param_2 = param_1;
    *(param_2 + 16) = 0;
    *(param_2 + 8) = *(param_2 + 16);
  }
  else {
    if (param_1 < *param_2) {
      uVar1 = func8_1(param_1,(param_2 + 8),*(param_2 + 8));
      *(param_2 + 8) = uVar1;
    }
    else {
      uVar1 = func8_1(param_1,*(param_2 + 0x10),*(param_2 + 0x10));
      *(param_2 + 0x10) = uVar1;
    }
  }
  return param_2;//heapAddr
}
