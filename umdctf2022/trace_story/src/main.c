undefined8 main(void){
  uint pid;
  code *userInput;
  long in_FS_OFFSET;
  undefined local_1018 [4104];
  long local_10;
  
  memcpy(local_1018,"Finishing\n",0xb);
  pid = fork();
  if (pid == 0) {
    // child process
    read_story();
  }
  if (debug != 0) {
    printf("[DEBUG] child pid: %d\n",pid);
  }
  userInput = read_input();
  setup_seccomp();
  (*userInput)();
  printf("%s",local_1018);
}
