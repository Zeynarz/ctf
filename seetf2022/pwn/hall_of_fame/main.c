int main(void)

{
  int iVar1;
  char *pcVar2;
  size_t sVar3;
  long in_FS_OFFSET;
  int counter;
  int o;
  char *pty;
  void *heap_pointer;
  ulong size;
  char *ptr;
  char *chunk;
  char option [3];
  char score [64];
  char word [100];
  long local_10;
  
  counter = 0;
  heap_pointer = sbrk(0);
  setup_IO(); // just a bunch of setvbufs
  while( true ) {
    do {
      print_statements(counter); // print menu
      printf("Choose> ");
      fflush(stdout);
      pcVar2 = fgets(option,3,stdin);
    } while (pcVar2 == 0x0);

    fflush(stdin);
    sVar3 = strcspn(option,"\n"); // Just sets null byte
    option[sVar3] = '\0';
    iVar1 = atoi(option);
    if (iVar1 == 1) {
      printf("\nHow many points did this person score? > ");
      fflush(stdout);
      pcVar2 = fgets(score,0x40,stdin);
      if (pcVar2 != 0x0) {
        fflush(stdin);
        sVar3 = strcspn(score,"\n"); // Just sets null byte
        score[sVar3] = '\0';
        size = strtol(score,&pty,10);
        ptr = malloc(size);
        chunk = ptr;
        printf("\nWho is this Hall of Famer > ");
        fflush(stdout);
        fgets(word,100,stdin);
        fflush(stdin);
        *(undefined8 *)chunk = word._0_8_;
        *(undefined8 *)(chunk + 8) = word._8_8_;
        *(undefined8 *)(chunk + 0x10) = word._16_8_;
        *(undefined8 *)(chunk + 0x18) = word._24_8_;
        *(undefined8 *)(chunk + 0x20) = word._32_8_;
        *(undefined8 *)(chunk + 0x28) = word._40_8_;
        *(undefined8 *)(chunk + 0x30) = word._48_8_;
        *(undefined8 *)(chunk + 0x38) = word._56_8_;
        *(undefined8 *)(chunk + 0x40) = word._64_8_;
        *(undefined8 *)(chunk + 0x48) = word._72_8_;
        *(undefined8 *)(chunk + 0x50) = word._80_8_;
        *(undefined8 *)(chunk + 0x58) = word._88_8_;
        *(undefined4 *)(chunk + 0x60) = word._96_4_;
        heap_pointer = ptr;
        counter = counter + 1;
    } else if (iVar1 == 2) {
        printf("\nThe position of latest addition is at %p\n",heap_pointer);
        printf("The position of PUTS is at %p\n",puts);

    } else if (iVar1 == 3) { 
        break;

    } else {
      puts("No choice Given!");
    }
  }
  puts("Exiting software...");
}
