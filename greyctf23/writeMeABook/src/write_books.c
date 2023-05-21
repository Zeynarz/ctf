void write_books(void)

{
  long in_FS_OFFSET;
  int choice;
  int index;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
LAB_00401964:
  print_menu();
  __isoc99_scanf("%d",&choice);
  getchar();
  if (choice == 1337) {
    if (secret_msg == 0) {
      printf("What is your favourite number? ");
      __isoc99_scanf("%d",&index);
      if (((0 < index) && (index < 11)) &&
         (*(books + (index + -1) * 0x10 + 8) != 0)) {
        // heap leak
        printf("You found a secret message: %p\n",
               *(books + (index + -1) * 0x10 + 8));
      }
      secret_msg = 1;
    }
  }
  else {
    if (1337 < choice) goto LAB_00401aa5;
    if (choice == 4) {
      if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
        return;
      }
      __stack_chk_fail();
    }
    if (4 < choice) goto LAB_00401aa5;
    if (choice == 3) {
      throw_book();
      goto LAB_00401964;
    }
    if (choice < 4) {
      if (choice == 1) {
        write_book();
      }
      else {
        if (choice != 2) goto LAB_00401aa5;
        rewrite_book();
      }
      goto LAB_00401964;
    }
  }
LAB_00401aa5:
  puts("Invalid choice.");
  goto LAB_00401964;
}



void write_book(void)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  int iVar3;
  ssize_t len;
  void *pvVar5;
  long in_FS_OFFSET;
  int index;
  size_t local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined local_28;
  long local_20;

  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  puts("\nAt which index of the shelf would you like to insert your book?");
  printf("Index: ");
  __isoc99_scanf("%d",&index);
  getchar(); // for the newline?
  if (((index < 1) || (10 < index)) ||
     (*(books + (index + -1) * 0x10 + 8) != 0)) {
    puts("Invaid slot!");
  }
  else {
    index = index + -1;
    local_48 = 0;
    local_40 = 0;
    local_38 = 0;
    local_30 = 0;
    local_28 = 0;
    puts("Write me a book no more than 32 characters long!");
    len = read(0,&local_48,0x20);
    iVar3 = index;
    local_50 = len + 0x10;
    pvVar5 = malloc(local_50); // will malloc len+0x10 bytes
    *(books + iVar3 * 0x10 + 8) = pvVar5;
    memcpy(*(books + index * 0x10 + 8),&local_48,len);
    uVar2 = author_signature._8_8_;
    puVar1 = (*(books + index * 0x10 + 8) + len);

    // write "by ..."
    // 16 bytes
    *puVar1 = author_signature._0_8_;
    puVar1[1] = uVar2;
    *(books + index * 0x10) = local_50;
    // so books is like
    // index1: size chunk
    // index2: size chunk
    puts("Your book has been published!\n");
  }
  if (local_20 != *(long *)(in_FS_OFFSET + 0x28)) {
    __stack_chk_fail();
  }
  return;
}

void rewrite_book(void)

{
  long lVar1;
  undefined8 uVar2;
  long in_FS_OFFSET;
  int index;
  ssize_t local_18;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  puts("\nAt which index of the shelf would you like to rewrite your book?");
  printf("Index: ");
  __isoc99_scanf("%d",&index);
  getchar();
  if (((index < 1) || (10 < index)) ||
     (*(long *)(books + (long)(index + -1) * 0x10 + 8) == 0)) {
    puts("Invaid slot!");
  }
  else {
    index = index + -1;
    puts("Write me the new contents of your book that is no longer than what it was before.");
    local_18 = read(0,*(books + index * 0x10 + 8),
                    *(books + index * 0x10));

    // heap overflow happens here
    // the size is the len+0x10, so the author signature will help us overflow
    uVar2 = author_signature._8_8_;
    lVar1 = *(books + index * 0x10 + 8);
    // put 8 bytes of author signature at the end of the book
    *(lVar1 + local_18) = author_signature._0_8
    ((undefined8 *)(lVar1 + local_18))[1] = uVar2;
    puts("Your book has been rewritten!\n");
  }
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
    __stack_chk_fail();
  }
  return;
}

void throw_book(void){
  long in_FS_OFFSET;
  int index;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  puts("\nAt which index of the shelf would you like to throw your book?");
  printf("Index: ");
  __isoc99_scanf("%d",&index);
  getchar();
  if (((index < 1) || (10 < index)) ||
     (*(long *)(books + (long)(index + -1) * 0x10 + 8) == 0)) {
    puts("Invaid slot!");
  }
  else {
    index = index + -1;
    free(*(books + index * 0x10 + 8));
    *(books + index * 0x10 + 8) = 0;
    puts("Your book has been thrown!\n");
  }

  // no uaf
  // but no clear the size?

  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

