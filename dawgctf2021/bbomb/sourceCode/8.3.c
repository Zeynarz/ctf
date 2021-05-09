void func8_3(void *param_1)

{
  if (param_1 != 0x0) {
    func8_3(*(param_1 + 8));
    func8_3(*(param_1 + 0x10));
    free(param_1);
  }
  return;
}

