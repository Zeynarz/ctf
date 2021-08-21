void getInp(void *param_1,uint param_2)

{
  ssize_t sVar1;
  
  sVar1 = read(0,param_1,(ulong)param_2);
  if ((int)sVar1 < 1) {
    Err("Read error");
  }
  *(undefined *)((long)param_1 + (long)(int)sVar1 + -1) = 0; //no check for newline 
  return;
}
