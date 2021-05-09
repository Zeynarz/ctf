#include <stdio.h>
int func4(int n);
int main(){
    printf("%d\n",func4(40));
}

int func4(int n){
  long lVar1;
  long lVar2;
  
  if (n < 1) {
    lVar1 = 0;
  }
  else {
    if (n == 1) {
      lVar1 = 1;
    }
    else {
      lVar2 = func4(n + -1);
      lVar1 = func4(n + -2);
      lVar1 = lVar1 + lVar2;
    }
  }
  return lVar1;
}
