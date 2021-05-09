char * func3_1(char *heapAddress)

{
  char cVar1;
  
  if (('@' 64  < *heapAddress) && (*heapAddress < '[' 91)) {
    *heapAddress = *heapAddress + -0xd 13;
    if (*heapAddress < 'A' 64) {
      cVar1 = '\x1a' 26;
    }
    else {
      cVar1 = '\0' 0;
    }
    *heapAddress = cVar1 + *heapAddress;
  }
  if (('`' 96 < *heapAddress) && (*heapAddress < '{' 123)) {
    *heapAddress = *heapAddress + -0xd 13;
    if (*heapAddress < 'a' 97) {
      cVar1 = '\x1a' 26;
    }
    else {
      cVar1 = '\0';
    }
    *heapAddress = cVar1 + *heapAddress;
  }
  return heapAddress;
}

