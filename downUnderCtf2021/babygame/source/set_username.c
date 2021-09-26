void set_username(void){
  FILE *__stream;
  size_t __n;
  
  puts("What would you like to change your username to?");
  __stream = stdin;
  __n = strlen(NAME);
  fread(NAME,1,__n,__stream);
  return;
}

