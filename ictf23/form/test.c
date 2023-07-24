#include <stdio.h>

int main(){
    int a = 0;
    printf("123%n %d\n",&a,a); // test to see if the write happens first before a is printed out
    return 0;
}
