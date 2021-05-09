
undefined8 func5(uint param_1)

{
  undefined8 uVar1;
  int local_c;
  
  if (((param_1 & 1) == 0)/*checking if last bit is 0*/ || ((int)param_1 < 2)) {
    uVar1 = 0;
  }
  else {
    local_c = 3;
    while (local_c < (int)param_1 / 2) {
      if ((int)param_1 % local_c == 0) {
        return 0;
      }
      local_c = local_c + 2;
    }
    uVar1 = 1;
  }
  return uVar1;
}

