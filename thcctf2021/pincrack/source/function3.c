void FUN_00101305(undefined8 input,undefined8 probKey,long param_3,long param_4)

{
  int local_4c;
  undefined local_48 [32];
  undefined auStack40 [24];
  long local_10;
  
  crypto_scrypt(input,6,probKey,0x10,0x200000,8,1,local_48,0x30);
  local_4c = 0;
  while (local_4c < 0x20) {
    *(local_4c + param_3) = local_48[local_4c];
    local_4c = local_4c + 1;
  }
  local_4c = 0;
  while (local_4c < 0x10) {
    *(undefined *)(local_4c + param_4) = local_48[local_4c + 0x20];
    local_4c = local_4c + 1;
  }
  return;
}

