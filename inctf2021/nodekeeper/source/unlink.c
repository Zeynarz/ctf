void Unlink(void)

{
  long in_FS_OFFSET;
  char local_31;
  int local_2c;
  long local_10;
  
  printf("Enter index: ");
  local_28 = getInt();
  if (*(long *)(Table + (ulong)local_28 * 8) == 0) {
    Err("Invalid index");
  }
  if (*(int *)(CountArr + (ulong)local_28 * 4) == 1) {
    Err("Can\'t unlink with only one chunk");
  }
  View(local_28);
  printf("Enter offset: ");
  local_24 = getInt();
  local_20 = *(undefined8 **)(Table + (ulong)local_28 * 8);
  local_18 = (undefined8 *)0x0;
  if ((local_24 == 0) || (*(uint *)(CountArr + (ulong)local_28 * 4) < local_24)) {
    Err("Invalid offset");
  }
  local_24 = local_24 - 1;
  if (local_24 == 0) {
    if (1 < *(uint *)(CountArr + (ulong)local_28 * 4)) {
      local_18 = local_20;
      *(undefined8 *)(Table + (ulong)local_28 * 8) = *local_20;
      *(int *)(CountArr + (ulong)local_28 * 4) = *(int *)(CountArr + (ulong)local_28 * 4) + -1;
    }
  }
  else {
    local_30 = 1;
    while (local_30 < local_24) {
      local_20 = (undefined8 *)*local_20;
      local_30 = local_30 + 1;
    }
    local_18 = (undefined8 *)*local_20;
    *local_20 = *(undefined8 *)*local_20;
    *(int *)(CountArr + (ulong)local_28 * 4) = *(int *)(CountArr + (ulong)local_28 * 4) + -1;
  }
  if (*(int *)(CountArr + (ulong)local_28 * 4) == 0) {
    *(undefined8 *)(Table + (ulong)local_28 * 8) = 0;
  }
  printf("Do you want to keep it (y/n)? ");
  getInp(&local_31,2);
  if ((local_31 == 'y') || (local_31 == 'Y')) {
    local_2c = 0;
    while ((local_2c < 10 && (*(long *)(Table + (long)local_2c * 8) != 0))) {
      local_2c = local_2c + 1;
    }
    if (9 < local_2c) {
      Err("No more space available");
    }
    *(undefined8 **)(Table + (long)local_2c * 8) = local_18;
    *(undefined4 *)(CountArr + (long)local_2c * 4) = 1;
  }
  else {
    free((void *)local_18[2]);
    *local_18 = 0;
    local_18[2] = 0;
    free(local_18);
  }
  puts("Success");
}
