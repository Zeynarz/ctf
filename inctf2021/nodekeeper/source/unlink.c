void Unlink(void)

{
  long in_FS_OFFSET;
  char userResponse;
  int local_2c;
  long local_10;
  
  printf("Enter index: ");
  nodeIndex = getInt();

  if (*(Table + nodeIndex * 8) == 0) {
    Err("Invalid index");
  }
  if (*(CountArr + nodeIndex * 4) == 1) {
    Err("Can\'t unlink with only one chunk");
  }

  View(nodeIndex);
  printf("Enter offset: ");
  objectIndex = getInt();
  object1ptr = *(Table + nodeIndex * 8);
  toFreeObjectPtr = 0x0;
  if ((objectIndex == 0) || (*(CountArr + nodeIndex * 4) < objectIndex)) {
    Err("Invalid offset");
  }
  objectIndex = objectIndex - 1;
  if (objectIndex == 0) {
    if (1 < *(CountArr + nodeIndex * 4)) {
      toFreeObjectPtr = object1ptr;
      *(Table + nodeIndex * 8) = *object1ptr; //fd
      *(CountArr + nodeIndex * 4) = *(CountArr + nodeIndex * 4) + -1;
      //toFreeObject still have fd in it
    }
  }
  else {
    local_30 = 1;
    while (local_30 < objectIndex) {
      object1ptr = *object1ptr;
      local_30 = local_30 + 1;
    }
    toFreeObjectPtr = *object1ptr;
    *object1ptr = **object1ptr;
    *(CountArr + nodeIndex * 4) = *(CountArr + nodeIndex * 4) + -1;
    //to free object stil lhave fd
  }
  if (*(CountArr + nodeIndex * 4) == 0) {
    *(Table + nodeIndex * 8) = 0;
  }
  printf("Do you want to keep it (y/n)? ");
  getInp(&userResponse,2);
  if ((userResponse == 'y') || (userResponse == 'Y')) {
    local_2c = 0;
    while ((local_2c < 10 && (*(Table + local_2c * 8) != 0))) {
      local_2c = local_2c + 1;
    }
    if (9 < local_2c) {
      Err("No more space available");
    }
    *(Table + local_2c * 8) = toFreeObjectPtr;
    *(CountArr + local_2c * 4) = 1;
  }
  else {
    free(toFreeObjectPtr[2]);
    *toFreeObjectPtr = 0;
    toFreeObjectPtr[2] = 0;
    free(toFreeObjectPtr);
  }
  puts("Success");
}
