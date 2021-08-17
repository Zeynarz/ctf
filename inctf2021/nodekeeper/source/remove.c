void Remove(void)

{
  void **ppvVar2;
  void *__ptr;
  void **local_20;
  
  printf("Enter index: ");
  userIndex = getInt();
  if (*(Table + userIndex * 8) == 0) {
    Err("Invalid index");
  }
  View(userIndex);
  printf("Which one?(1337 for all) ");
  uVar4 = getInt();
  if (((uVar4 == 0) || (*(CountArr + (ulong)userIndex * 4) < uVar4)) && (uVar4 != 0x539)) {
    Err("Invalid offset");
  }
  uVar1 = uVar4 - 1;
  local_20 = *(Table + userIndex * 8);
  if (uVar1 == 0x538) {
    while (local_20 != 0x0) {
      ppvVar2 = *local_20;
      if (local_20[2] == 0x0) {
        Err("Error");
      }
      free(local_20[2]);
      *local_20 = 0x0;
      local_20[2] = 0x0;
      free(local_20);
      local_20 = ppvVar2;
    }
    *(Table + userIndex * 8) = 0;
    *(CountArr + userIndex * 4) = 0;
  }
  else {
    if (uVar4 == 1) {
      if (*(uint *)(CountArr + (ulong)userIndex * 4) < 2) {
        *(undefined8 *)(Table + (ulong)userIndex * 8) = 0;
        *(undefined4 *)(CountArr + (ulong)userIndex * 4) = 0;
      }
      else {
        *(Table + (ulong)userIndex * 8) = *local_20;
        *(CountArr + (ulong)userIndex * 4) = *(CountArr + (ulong)userIndex * 4) + -1;
      }
      if (local_20[2] == 0x0) {
        Err("Error");
      }
      free(local_20[2]);
      *local_20 = 0x0;
      local_20[2] = 0x0;
      free(local_20);
    }
    else {
      if ((uVar4 == 1) || (*(CountArr + userIndex * 4) <= uVar1)) {
        Err("Invalid offset");
      }
      else {
        local_2c = 1;
        while (local_2c < uVar1) {
          local_20 = *local_20;
          local_2c = local_2c + 1;
        }
        __ptr = *local_20;
        *local_20 = **local_20;
        *(CountArr + userIndex * 4) = *(CountArr + userIndex * 4) + -1;
        if (*(__ptr + 0x10) == 0) {
          Err("Error");
        }
        free(*(__ptr + 0x10));
        free(__ptr);
      }
    }
  }
  puts("Success");
  return;
}
