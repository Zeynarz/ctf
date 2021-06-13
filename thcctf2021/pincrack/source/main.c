void main(){
 if (param_1 != 2) {
    puts("[!] Bad number of arguments.");
    printf("Usage: %s <6-digits-PIN-code>\n",*param_2);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  sVar2 = strlen(param_2[1]);
  if (sVar2 != 6) {
    puts("[!] The PIN-code is exactly 6 digits long. I am so kind.");
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  iterate = 0;
  while( true ) {
    if (5 < iterate) {
      input = *param_2[1];
      local_f8 = *(param_2[1] + 1);
      puts("[*] Thanks for your try! I am checking...");
      FUN_00101245(&input,&convertedInput,&convertedInput);
      FUN_001012bb(&convertedInput,&local_d8,&local_d8);
      FUN_00101305(&input,0x4b27cc1ab8fb673e,&local_b8,&local_e8);
      iVar1 = strncmp(&local_d8,&DAT_00104020,0x14);
      if (iVar1 == 0) {
        iVar1 = FUN_001013ee(&DAT_00104040,DAT_00104098 & 0xffffffff,&local_b8,&local_e8,&local_98);
        local_f0 = (long)iVar1;
        *(&local_98 + local_f0) = 0;
        printf("Good PIN! Here is your flag:\n%s\n",&local_98);
      }
      else {
        puts("Nope.");
      }
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
    if ((*(byte *)((long)iterate + param_2[1]) < 0x30) ||
       (0x39 < *(byte *)((long)iterate + param_2[1]))) break;
    iterate = iterate + 1;
  }
  puts("[!] Only digits [0-9]. Really kind.");
                    /* WARNING: Subroutine does not return */
  exit(1);
}
