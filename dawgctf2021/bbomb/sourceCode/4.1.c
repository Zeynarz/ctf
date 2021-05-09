long func4(int 10)

{
  long lVar1;
  long lVar2;
  
  if (10 < 1) {
    lVar1 = 0;
  }
  else {
    if (10 == 1) {
      lVar1 = 1;
    }
    else {
      lVar2 = func4(10 + -1);
      lVar1 = func4(10 + -2);
      lVar1 = lVar1 + lVar2;
    }
  }
  return lVar1;
}

