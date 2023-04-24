undefined8 main(undefined4 param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  int iVar2;
  FILE *__stream;
  long in_FS_OFFSET;
  int i;
  char acStack88 [32];
  char acStack56 [40];
  long lStack16;
  
  lStack16 = *(long *)(in_FS_OFFSET + 0x28);
  megaInit();
  _global_argc = param_1;
  _global_argv = param_2;
  _global_envp = param_3;
  print_art();
  puts(
      "Welcome, human, to the 42nd centennial dolphin acrobatics show!  Better get to it.\nThese dolphins aren\'t going to train themselves..."
      );
  uVar1 = getppid();
  snprintf(acStack88,0x14,"/proc/%d/comm",(ulong)uVar1);
  __stream = fopen(acStack88,"r");
  fgets(acStack56,0x20,__stream);
  i = 0;
  while(true) {
    if (0x1f < i) {
LAB_001337dc:
      iVar2 = strncmp("fish",acStack56,4);
      if (iVar2 == 0) {
        puts("\nThe dolphins aren\'t in the mood for fish right now.");
      }
      else {
        iVar2 = strncmp("bash",acStack56,4);
        if (iVar2 == 0) {
          puts("\nThe dolphins don\'t appreciate your threats of violence.");
        }
        else {
          iVar2 = strncmp("tidbits",acStack56,7);
          if (iVar2 == 0) {
            puts("\nUpon seeing the tidbits, the dolphins begin their performance.");
            puts(
                "\nAs you give them the signal, you are amazed by the dolphins\' uncanny ability to\nperform a double-backwards-somersault through a hoop whilst whistling \"The Star\nSpangled Banner.\"  You can\'t help but wonder if there\'s some hidden meaning behind\ntheir actions."
                );
            iVar2 = tricks();
            if (iVar2 == 0) {
              FUN_00121960(); // gives flag?
            }
          }
          else {
            puts("\nThe dolphins are hungry...");
          }
        }
      }


      if (lStack16 == *(long *)(in_FS_OFFSET + 0x28)) {
        return 0;
      }
      __stack_chk_fail();
    }

    if (acStack56[i] == '\n') {
      acStack56[i] = '\0';
      goto LAB_001337dc;
    }
    i = i + 1;
  }
}



undefined8 tricks(void) {
  FILE *__stream;
  char *pcVar1;
  undefined8 uVar2;
  long in_FS_OFFSET;
  int local_434;
  char local_418 [1032];
  long local_10;

  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  __stream = popen("/bin/grep tidbits /proc/*/comm","r");
  if (__stream == (FILE *)0x0) {
    puts("ERROR: This challenge depends on grep.");
    exit(1);
  }
  putchar(10);
  local_434 = 0;
  while ((pcVar1 = fgets(local_418,0x400,__stream), pcVar1 != 0x0 && (local_434 < 6))) {
    printf("Performed trick %c...\n",(local_434 + 0x41));
    local_434 = local_434 + 1;
  }
  if (local_434 < 6) {
    if (4 < local_434) {
      uVar2 = 0;
      goto LAB_0014fa83;
    }
    puts("\nYou ran out of treats.  The dolphins are no longer following your lead.");
  }
  else {
    puts("\nYou overfed the dolphins and they decided to take a nap.");
  }
  uVar2 = 1;
LAB_0014fa83:
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar2;
  }
  __stack_chk_fail();

