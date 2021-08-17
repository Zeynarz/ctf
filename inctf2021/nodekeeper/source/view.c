void View(uint index)

{
  undefined8 *puVar1;
  uint iterate;
  undefined8 *heapObject;
  
  iterate = 0;
  heapObject = *(Table + index * 8);
  while (iterate < *(CountArr + index * 4)) {
    puVar1 = *heapObject;
    printf("Node %d Offset %d : %s\n",index,(iterate + 1),heapObject[2]);
    iterate = iterate + 1;
    heapObject = puVar1;
  }
  return;
}
