void Add(void){
  uint userSize;
  void *nameChunk;
  undefined8 *heapPtr;
  int index;
  int amountOfChunks;
  int iterate;
  
  amountOfChunks = 0;
  iterate = 0;
  while (iterate < 10) {
    amountOfChunks = amountOfChunks + *(CountArr + iterate * 4);
    iterate = iterate + 1;
  }
  if (9 < amountOfChunks) {
    Err("Can\'t add"); //maximum nine objects
  }
  index = 0;
  while ((index < 10 && (*(Table + index * 8) != 0))) {
    index = index + 1; //get index?
  }
  if (9 < index) {
    Err("No more space available");
  }
  printf("Enter length : ");
  userSize = getInt();
  if ((userSize == 0) || (0x60 < userSize)) {
    Err("Invalid size");
  }
  nameChunk = malloc(userSize);
  heapPtr = malloc(0x18);
  *heapPtr = 0;
  *(heapPtr + 1) = userSize;
  heapPtr[2] = nameChunk;
  printf("Enter data : ");
  getInp(nameChunk,userSize);
  *(CountArr + index * 4) = 1;
  *(Table + index * 8) = heapPtr;
  puts("Success");
  return;
  ///////////////
}
