undefined8 main(void){
  time_t tVar1;
  long in_FS_OFFSET;
  int choice;
  int local_79c;
  char library [1928];
  long local_10;
  
  local_10 = *(in_FS_OFFSET + 0x28);
  setup();
  srand(time(0));
  memset(library,0,0x780);
  while (n < 10) {
    local_79c = rand() % 0x1e; // get random book, difference between book strings are 0x40
    strcpy(library + n * 0x80,s_The_Catcher_in_the_Rye_00104020 + local_79c * 0x40);
    // one entry has 0x80 bytes of space
    n = n + 1;
  }
  do {
    menu();
    __isoc99_scanf("%d",&choice);
    switch(choice) {
    default:
      puts("Invalid choice. Please try again.");
      break;
    case 1:
      displayBookList(library);
      break;
    case 2:
      if (n < 0xf) {
        // max 14 books
        addBook(library);
        sort(library);
      }
      else {
        puts("The book list is full.");
      }
      break;
    case 3:
      addComment(library);
      break;
    case 4:
      clearBooks(library);
      break;
    case 5:
      puts("Exiting...");
    }
  } while (choice != 5);
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}

void displayBookList(long param_1){
  uint i;

  puts("Current Book List:");
  i = 0;
  while (i < n) {
    printf("%d. ",i + 1);
    write(1,param_1 + i * 0x80,0x40);
    puts("");
    i = i + 1;
  }
  return;
}


void addBook(long param_1){
  int iVar1;
  ssize_t sVar2;
  long in_FS_OFFSET;
  char title [0x48];
  long local_10;
  local_10 = *(long *)(in_FS_OFFSET + 0x28);


  printf("Book title: ");
  iVar1 = read(0,title,0x3f); // A book title can only be 0x40 bytes long
  if (title[iVar1 - 1] == '\n') {
    title[iVar1 - 1] = '\0';
  }
  memcpy(param_1 + n * 0x80,title,iVar1);
  n = n + 1;

  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
    __stack_chk_fail();
  }
  return;
}


void addComment(long param_1){
  int iVar1;
  ssize_t sVar2;
  long in_FS_OFFSET;
  uint index;
  char comment [72];
  long local_10;
  local_10 = *(long *)(in_FS_OFFSET + 0x28);

  printf("Index: ");
  __isoc99_scanf("%d",index); // where is the &? is it supposed to be uninitialised var vuln?
  if (index < n) { // "%d", so neg num vuln exists
    // I think you have to use uninitialised vuln to write index, and use - to bypass scanf
    iVar1 = read(0,comment,0x3f);
    if (comment[iVar1 + -1] == '\n') {
      comment[iVar1 + -1] = '\0';
    }
    memcpy(param_1 + index * 0x80 + 0x40,comment,iVar1);
    // overwrite ret of memcpy?
  }
  else {
    puts("Index must be less than the number of books.");
  }

  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
    __stack_chk_fail();
  }
  return;
}


void clearBooks(void *param_1){
  memset(param_1,0,n << 7);
  n = 0;
  return;
}


void sort(long param_1){
  long lVar1;
  int ret;
  undefined8 *book;
  long lVar20;
  long in_FS_OFFSET;
  int i;
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  
  i = n - 2;
  while (-1 < i) {
    ret = strcmp((param_1 + (i + 1) * 0x80),(param_1 + i * 0x80));
    // if ret > 0, the 1st param (the further one) is greater
    // if ret < 0, the 2nd param (the closer one) is greater
   

    if ((ret < 0) && (i != n)) { // the closer one > the further one
      book = (param_1 + i * 0x80);
      // get the title, one var is 8 bytes
      uVar2 = book[0];
      uVar3 = book[1];
      uVar4 = book[2];
      uVar5 = book[3];
      uVar6 = book[4];
      uVar7 = book[5];
      uVar8 = book[7];
      uVar9 = book[6];

      lVar20 = param_1 + i * 0x80;
      // get the comment
      uVar10 = *(lVar20 + 0x40);
      uVar11 = *(lVar20 + 0x48);
      uVar12 = *(lVar20 + 0x50);
      uVar13 = *(lVar20 + 0x58);
      uVar14 = *(lVar20 + 0x60);
      uVar15 = *(lVar20 + 0x68);
      uVar16 = *(lVar20 + 0x78);
      uVar17 = *(lVar20 + 0x70);

      // copy stuff from the further one to the closer one
      memcpy((param_1 + i * 0x80),(param_1 + (i + 1) * 0x80),0x40);
      memcpy((param_1 + i * 0x80 + 0x40),(param_1 + (i + 1) * 0x80 + 0x40),0x40);

      // copy stuff from closer one to further one
      book = (param_1 + (i + 1) * 0x80);
      book[0] = uVar2;
      book[1] = uVar3;
      book[2] = uVar4;
      book[3] = uVar5;
      book[4] = uVar6;
      book[5] = uVar7;
      book[6] = uVar9;
      book[7] = uVar8;
      lVar20 = param_1 + ((long)i + 1) * 0x80;
      *(lVar20 + 0x40) = uVar10;
      *(lVar20 + 0x48) = uVar11;
      *(lVar20 + 0x50) = uVar12;
      *(lVar20 + 0x58) = uVar13;
      *(lVar20 + 0x60) = uVar14;
      *(lVar20 + 0x68) = uVar15;
      *(lVar20 + 0x70) = uVar17;
      *(lVar20 + 0x78) = uVar16;
      i = i + 1;
    }
    else {
      i = i - 1;
    }
  }
  if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}
