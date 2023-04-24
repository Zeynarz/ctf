basic_string * obfuscate(basic_string *param_1)

{
  char *pcVar1;
  ulong uVar2;
  ulong in_RSI;
  int local_1c;
  
  local_1c = 0;
  while( true ) {
    uVar2 = std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::length();
    if (uVar2 <= (ulong)(long)local_1c) break;
    pcVar1 = (char *)std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::
                     operator[](in_RSI);
    *pcVar1 = *pcVar1 + '\a';
    local_1c = local_1c + 1;
  }
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string
            (param_1);
  return param
