void Link(void)

{
  uint indexTo;
  uint indexFrom;
  uint local_24;
  undefined8 *heapToObject;
  
  printf("Enter to index: ");
  indexTo = getInt(); //negative nums? doesnt work cause 64bit and int 32bit
  if (*(Table + indexTo * 8) == 0) {
    Err("Invalid index");
  }
  printf("Enter from index: ");
  indexFrom = getInt();
  if (*(Table + indexFrom * 8) == 0) {
    Err("Invalid index");
  }
  if (indexFrom == indexTo) {
    Err("Can\'t link Node to itself");
  }

  if ((*(CountArr + indexTo * 4) == 10) ||
     (10 < (*(CountArr + indexFrom * 4) + *(CountArr + indexTo * 4)))) {
    Err("Can\'t link");
  }
  heapToObject = *(Table + indexTo * 8);
  local_24 = 1;
  while (local_24 < amountOfOffsets) {
    heapToObject = *heapToObject;
    local_24 = local_24 + 1;
  }
  *heapToObject = *(Table + indexFrom * 8);
  *(Table + indexFrom * 8) = 0;
  *(CountArr + indexTo * 4) =
  *(CountArr + indexTo * 4) + *(CountArr + (ulong)indexFrom * 4);
  *(CountArr + indexFrom * 4) = 0;
  puts("Success");
  ///////////////////
  return;
}
