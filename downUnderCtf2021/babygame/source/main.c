void main(EVP_PKEY_CTX *param_1){
  int iVar1;
  
  init(param_1);
  puts("Welcome, what is your name?");
  read(0,NAME,0x20);
  RANDBUF = "/dev/urandom";
  while (true) {
    while( true ) {
      while( true ) {
        print_menu();
        iVar1 = get_num();
        if (iVar1 != 0x539) break;
        game();
      }
      if (iVar1 < 0x53a) break;
LAB_0010126c:
      puts("Invalid choice.");
    }
    if (iVar1 == 1) {
      set_username();
    }
    else {
      if (iVar1 != 2) goto LAB_0010126c;
      print_username();
    }
  }
}
