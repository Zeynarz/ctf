void echo_inner(void *buffer,int len){
  size_t sVar1;
  
  sVar1 = fread(buffer,1,len,stdin);
  *(buffer + sVar1) = 0;
  puts("You said:");
  printf("%s",buffer);
  return;
}
