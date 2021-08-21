void Remove(void)

{
  void **fd;
  void *toFreePtr;
  void **object1Ptr;
  
  printf("Enter index: ");
  nodeIndex = getInt();
  if (*(Table + nodeIndex * 8) == 0) {
    Err("Invalid index");
  }
  View(nodeIndex);
  printf("Which one?(1337 for all) ");
  objectIndex = getInt();
  if (((objectIndex == 0) || (*(CountArr + (ulong)nodeIndex * 4) < objectIndex)) && (objectIndex != 0x539)) {
    Err("Invalid object");
  }
  objectIndex-1 = objectIndex - 1;
  object1Ptr = *(Table + nodeIndex * 8);
  if (objectIndex-1 == 0x538) {
    while (object1Ptr != 0x0) {
      fd = *object1Ptr;
      if (object1Ptr[2] == 0x0) { //no string chunk
        Err("Error");
      }
      free(object1Ptr[2]); //free string chunk
      *object1Ptr = 0x0;
      object1Ptr[2] = 0x0;
      free(object1Ptr);
      object1Ptr = fd;
    }
    *(Table + nodeIndex * 8) = 0;
    *(CountArr + nodeIndex * 4) = 0;
  }
  else { //normal free
    if (objectIndex == 1) {
      if (*(CountArr + (ulong)nodeIndex * 4) < 2) { //count = 1 offset is 1-indexed ?
        *(Table + (ulong)nodeIndex * 8) = 0;
        *(CountArr + (ulong)nodeIndex * 4) = 0;
      }
      else {
        *(Table + (ulong)nodeIndex * 8) = *object1Ptr;
        *(CountArr + (ulong)nodeIndex * 4) = *(CountArr + (ulong)nodeIndex * 4) + -1;
      }
      if (object1Ptr[2] == 0x0) {
        Err("Error");
      }
      free(object1Ptr[2]);
      *object1Ptr = 0x0;
      object1Ptr[2] = 0x0;
      free(object1Ptr);
    }
    else {
      if ((objectIndex == 1) || (*(CountArr + nodeIndex * 4) <= objectIndex-1)) {
        Err("Invalid object");
      }
      else {
        local_2c = 1;
        while (local_2c < objectIndex-1) {
          object1Ptr = *object1Ptr;
          local_2c = local_2c + 1;
        }
        toFreePtr = *object1Ptr;
        *object1Ptr = **object1Ptr; //next fd
        *(CountArr + nodeIndex * 4) = *(CountArr + nodeIndex * 4) + -1;
        if (*(toFreePtr + 0x10) == 0) {
          Err("Error");
        }
        free(*(toFreePtr + 0x10));
        free(toFreePtr);
      }
    }
  }
  puts("Success");
  return;
}
