undefined8 main(void){
  undefined uVar1;
  long in_FS_OFFSET;
  int local_64;
  int local_60;
  int local_5c;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined2 local_40;
  undefined local_3e;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined2 local_20;
  undefined local_1e;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_3e = 0;
  local_58 = 0x26666fe8ea686a28;
  local_50 = 0xaee8ebe666666666;
  local_48 = 0xeba5eb4e666e6e66;
  local_40 = 0xafa5;
  local_38 = 0;
  local_30 = 0;
  local_28 = 0;
  local_20 = 0;
  local_1e = 0;
  local_5c = FUN_001007ab(100);
  local_5c = local_5c + 1000;
  puts("What is the Random number?");
  __isoc99_scanf(&DAT_00100a4f,&local_64);
  local_64 = local_64 % 100;
  if ((local_64 < local_5c) || (local_5c < local_64)) {
    puts("Loser");
  }
  else {
    puts("That\'s right!");
    local_60 = 0;
    while (local_60 < 0x1a) {
      uVar1 = FUN_0010077a(*(undefined *)((long)&local_58 + (long)local_60),3);
      *(undefined *)((long)&local_38 + (long)local_60) = uVar1;
      local_60 = local_60 + 1;
    }
  }
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



int FUN_001007ab(int param_1){
  long in_FS_OFFSET;
  int local_14;
  long local_10;

  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  getrandom(&local_14,4,1); // get random int into local_14
  if (local_14 < 0) {
    local_14 = -local_14; // make sure its negative
  }


  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return local_14 % 100 + 1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}
