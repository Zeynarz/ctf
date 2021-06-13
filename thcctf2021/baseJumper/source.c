void main(){
    if (*(char *)param_2[1] == '\0') {
      uVar1 = 0xffffffff;
    }
    else {
      sVar2 = strlen((char *)param_2[1]);
      sVar3 = strlen(local_1c8);
      if (sVar2 == sVar3) {
        iterate = 0;
        while( true ) {
          sVar2 = strlen((char *)param_2[1]);
          if (sVar2 - 1 <= iterate) break; //check if index in bounds
          if (*(iterate + param_2[1]) != local_1c8[iterate]) {
            puts("Wrong password.");
            if (iterate == 0) {
              uVar1 = 0xffffffff;
            }
            else {
              uVar1 = 0x11;
            }
            goto LAB_00401d7a;
          }
          iterate = iterate + 1;
        }
        puts("Congratulations, you can validate with this password once decoded.");
        uVar1 = 0x2a;
      }
      else {
        iterate = 0;
        while( true ) {
          sVar2 = strlen((char *)param_2[1]);
          if (sVar2 <= (ulong)(long)iterate) break;
          if (*(char *)((long)iterate + param_2[1]) != local_1c8[iterate]) {
            puts("Wrong password.");
            uVar1 = 0xffffffff;
            goto LAB_00401d7a;
          }
          iterate = iterate + 1;
        }
        puts("Wrong password.");
        uVar1 = 0x11;
      }
    }
  }
  else {
    printf("Syntax : %s PASS\n",*param_2);
    uVar1 = 0xffffffff;
  }
LAB_00401d7a:
  if (local_20 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar1;
}
}
