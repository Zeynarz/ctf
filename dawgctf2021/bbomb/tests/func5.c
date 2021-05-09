#include <stdio.h>
int func5(int n);
int func5(int n){
  int uVar1;
  int local_c;
  
  if (((n & 1) == 0)/*checking if last bit is 0*/ || (n < 2)) {
    uVar1 = 0;
  }
  else {
    local_c = 3;
    while (local_c < n / 2) {
      if (n % local_c == 0) {
        return 0;
      }
      local_c = local_c + 2;
    }
    uVar1 = 1;
  }
  return uVar1;
}

int main(){
    printf("%d\n",func5(6197));
}
