char * func3_2(char *heapAddress)

{
  char cVar1;
  
  if ((' ' 32< *heapAddress) && (*heapAddress != '\x7f' 127)) {
    *heapAddress = *heapAddress + -0x2f 47;
    if (*heapAddress < '!' 33) {
      cVar1 = '^' 94;
    }
    else {
      cVar1 = '\0';
    }
    *heapAddress = cVar1 + *heapAddress;
  }
  return heapAddress;
}

