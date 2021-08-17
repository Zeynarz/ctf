void main(void)

{
  undefined4 uVar1;
  
  initialize();
  signal(0xe,handler);
  do {
    uVar1 = menu();
    switch(uVar1) {
    case 1:
      Add();
      break;
    case 2:
      Remove();
      break;
    case 3:
      Link();
      break;
    case 4:
      Unlink();
      break;
    case 5:
      Err(&DAT_001032e0);
    default:
      puts("Invalid Choice");
    }
  } while( true );
}
