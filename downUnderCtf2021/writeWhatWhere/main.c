void main(EVP_PKEY_CTX *param_1)

{
  int iVar1;
  long in_FS_OFFSET;
  undefined4 what;
  char whr [24];
  undefined8 local_10;
  
  init(param_1);

  puts("write");
  puts("what?");
  read(0,&what,4);

  puts("where?");
  read(0,whr,9);
  iVar1 = atoi(whr);
  iVar1 = what;
  exit(0);
}
