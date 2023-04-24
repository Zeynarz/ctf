void admin_console(void)

{
  bool bVar1;
  basic_ostream *pbVar2;
  basic_string local_78 [32];
  basic_string<char,std::char_traits<char>,std::allocator<char>> local_58 [47];
  allocator local_29;
  duration<long,std::ratio<1l,1000l>> local_28 [12];
  int local_1c [3];
  
  do {
    clear_terminal();
    std::allocator<char>::allocator();
                    /* try { // try from 0040393a to 0040393e has its CatchHandler @ 00403b8b */
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::
    basic_string<std::allocator<char>>(local_58,"federation_logo.txt",&local_29);
                    /* try { // try from 00403946 to 0040394a has its CatchHandler @ 00403b7a */
    print_file((basic_string *)local_58);
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::
    _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev(local_58);
    std::allocator<char>::~allocator((allocator<char> *)&local_29);
    pbVar2 = std::operator<<((basic_ostream *)std::cout,"--------------");
    std::basic_ostream<char,std::char_traits<char>>::operator<<
              ((basic_ostream<char,std::char_traits<char>> *)pbVar2,
               std::_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_);
    pbVar2 = std::operator<<((basic_ostream *)std::cout,"Admin Terminal");
    std::basic_ostream<char,std::char_traits<char>>::operator<<
              ((basic_ostream<char,std::char_traits<char>> *)pbVar2,
               std::_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_);
    pbVar2 = std::operator<<((basic_ostream *)std::cout,"--------------");
    std::basic_ostream<char,std::char_traits<char>>::operator<<
              ((basic_ostream<char,std::char_traits<char>> *)pbVar2,
               std::_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_);
    pbVar2 = std::operator<<((basic_ostream *)std::cout,"OPTIONS:");
    std::basic_ostream<char,std::char_traits<char>>::operator<<
              ((basic_ostream<char,std::char_traits<char>> *)pbVar2,
               std::_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_);
    pbVar2 = std::operator<<((basic_ostream *)std::cout,"presidential_decree");
    std::basic_ostream<char,std::char_traits<char>>::operator<<
              ((basic_ostream<char,std::char_traits<char>> *)pbVar2,
               std::_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_);
    pbVar2 = std::operator<<((basic_ostream *)std::cout,"adjust_economy");
    std::basic_ostream<char,std::char_traits<char>>::operator<<
              ((basic_ostream<char,std::char_traits<char>> *)pbVar2,
               std::_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_);
    pbVar2 = std::operator<<((basic_ostream *)std::cout,"military_conquest");
    std::basic_ostream<char,std::char_traits<char>>::operator<<
              ((basic_ostream<char,std::char_traits<char>> *)pbVar2,
               std::_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_);
    pbVar2 = std::operator<<((basic_ostream *)std::cout,"law_enforcement");
    std::basic_ostream<char,std::char_traits<char>>::operator<<
              ((basic_ostream<char,std::char_traits<char>> *)pbVar2,
               std::_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_);
    pbVar2 = std::operator<<((basic_ostream *)std::cout,"logout");
    std::basic_ostream<char,std::char_traits<char>>::operator<<
              ((basic_ostream<char,std::char_traits<char>> *)pbVar2,
               std::_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_);
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string();
                    /* try { // try from 00403a75 to 00403b5e has its CatchHandler @ 00403ba5 */
    std::operator<<((basic_ostream *)std::cout,">> ");
    std::operator>>((basic_istream *)std::cin,local_78);
    bVar1 = std::operator==(local_78,"presidential_decree");
    if (bVar1 == false) {
      bVar1 = std::operator==(local_78,"adjust_economy");
      if (bVar1 != false) {
        adjust_economy();
        goto LAB_00403b5f;
      }
      bVar1 = std::operator==(local_78,"military_conquest");
      if (bVar1 != false) {
        military_conquest();
        goto LAB_00403b5f;
      }
      bVar1 = std::operator==(local_78,"law_enforcement");
      if (bVar1 != false) {
        law_enforcement();
        goto LAB_00403b5f;
      }
      bVar1 = std::operator==(local_78,"logout");
      if (bVar1 == false) {
        pbVar2 = std::operator<<((basic_ostream *)std::cout,"Invalid Option!");
        std::basic_ostream<char,std::char_traits<char>>::operator<<
                  ((basic_ostream<char,std::char_traits<char>> *)pbVar2,
                   std::_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_);
        local_1c[0] = 2000;
        std::chrono::duration<long,std::ratio<1l,1000l>>::duration<int,void>(local_28,local_1c);
        std::this_thread::sleep_for<long,std::ratio<1l,1000l>>((duration *)local_28);
        goto LAB_00403b5f;
      }
      bVar1 = false;
    }
    else {
      presidential_decree();
LAB_00403b5f:
      bVar1 = true;
    }
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::
    _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
              ((basic_string<char,std::char_traits<char>,std::allocator<char>> *)local_78);
    if (!bVar1) {
      return;
    }
  } while( true );
}
