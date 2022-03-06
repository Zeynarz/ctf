void read_story(void)

{
  uint pid;
  int fileFd;
  ssize_t readLen;
  long in_FS_OFFSET;
  undefined fileContent [4104];
  undefined8 local_10;
  
  do {
    pid = getpid();
    if ((pid & 1) == 0) {
      fileFd = open("readstory.txt",0);
      if (fileFd == 0) {
        if (debug != 0) {
          puts("Error when reading story.");
        }
        exit(1);
      }
      readLen = read(fileFd,fileContent,4096);
      if (readLen == 0) {
        if (debug != 0) {
          puts("Didn\'t read anything.");
        }
        exit(1);
      }
      close(fileFd);
    }
    sleep(1);
  } while( true );
}
