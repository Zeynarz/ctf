void func8_2(undefined *param_1,long param_2,int *param_3)
//heap chain, inputHeap,pointer to a 0
{
  if (param_1 != 0x0) {
    *(*param_3 + param_2) = *param_1;
    *param_3 = *param_3 + 1;//change 0 to 1
    func8_2(*(param_1 + 8),param_2,param_3,param_2);
    func8_2(*(param_1 + 0x10),param_2,param_3,param_2);
  }
  return;
}
