void login_page(void)

{
  bool bVar1;
  bool bVar2;
  basic_ostream *pbVar3;
  basic_ostream<char,std::char_traits<char>> *this;
  basic_string local_e8 [32];
  basic_string local_c8 [32];
  basic_string<char,std::char_traits<char>,std::allocator<char>> local_a8 [47];
  allocator local_79;
  basic_string local_78 [32];
  basic_string local_58 [32];
  duration<long,std::ratio<1l,1000l>> local_38 [12];
  int local_2c [3];
  
  do {
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string();
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string();
                    /* try { // try from 00403c68 to 00403c6c has its CatchHandler @ 00403ebf */
    clear_terminal();
    std::allocator<char>::allocator();
                    /* try { // try from 00403c8c to 00403c90 has its CatchHandler @ 00403e82 */
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::
    basic_string<std::allocator<char>>(local_a8,"federation_logo.txt",&local_79);
                    /* try { // try from 00403c9b to 00403c9f has its CatchHandler @ 00403e6e */
    print_file((basic_string *)local_a8);
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::
    _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev(local_a8);
    std::allocator<char>::~allocator((allocator<char> *)&local_79);
                    /* try { // try from 00403cc5 to 00403d54 has its CatchHandler @ 00403ebf */
    pbVar3 = std::operator<<((basic_ostream *)std::cout,"------------------------------");
    std::basic_ostream<char,std::char_traits<char>>::operator<<
              ((basic_ostream<char,std::char_traits<char>> *)pbVar3,
               std::_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_);
    pbVar3 = std::operator<<((basic_ostream *)std::cout,"Galactic Federation Login Page");
    std::basic_ostream<char,std::char_traits<char>>::operator<<
              ((basic_ostream<char,std::char_traits<char>> *)pbVar3,
               std::_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_);
    pbVar3 = std::operator<<((basic_ostream *)std::cout,"------------------------------");
    std::basic_ostream<char,std::char_traits<char>>::operator<<
              ((basic_ostream<char,std::char_traits<char>> *)pbVar3,
               std::_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_);
    std::operator<<((basic_ostream *)std::cout,"USERNAME: ");
    std::operator>>((basic_istream *)std::cin,local_e8);
    std::operator<<((basic_ostream *)std::cout,"PASSWORD: ");
    std::operator>>((basic_istream *)std::cin,local_c8);
    bVar1 = false;
                    /* try { // try from 00403d71 to 00403da5 has its CatchHandler @ 00403e93 */
    obfuscate(local_78);
    bVar2 = std::operator==(local_78,"hktpu");
    if (bVar2 == false) {
LAB_00403dc9:
      bVar2 = false;
    }
    else {
      obfuscate(local_58);
      bVar1 = true;
      bVar2 = std::operator==(local_58,"8fs7}:f~Y;unS:yfqL;uZ");
      if (bVar2 == false) goto LAB_00403dc9;
      bVar2 = true;
    }
    if (bVar1) {
      std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::
      _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
                ((basic_string<char,std::char_traits<char>,std::allocator<char>> *)local_58);
    }
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::
    _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
              ((basic_string<char,std::char_traits<char>,std::allocator<char>> *)local_78);
    if (bVar2) {
                    /* try { // try from 00403df5 to 00403e4a has its CatchHandler @ 00403ebf */
      admin_console();
    }
    else {
      pbVar3 = std::operator<<((basic_ostream *)std::cout,"Incorrect Username or Password!");
      this = (basic_ostream<char,std::char_traits<char>> *)
             std::basic_ostream<char,std::char_traits<char>>::operator<<
                       ((basic_ostream<char,std::char_traits<char>> *)pbVar3,
                        std::_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_);
      std::basic_ostream<char,std::char_traits<char>>::operator<<
                (this,std::_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_);
      local_2c[0] = 2000;
      std::chrono::duration<long,std::ratio<1l,1000l>>::duration<int,void>(local_38,local_2c);
      std::this_thread::sleep_for<long,std::ratio<1l,1000l>>((duration *)local_38);
    }
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::
    _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
              ((basic_string<char,std::char_traits<char>,std::allocator<char>> *)local_c8);
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::
    _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
              ((basic_string<char,std::char_traits<char>,std::allocator<char>> *)local_e8);
  } while( true );
}
