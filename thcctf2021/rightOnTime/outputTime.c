#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    long current = (time(NULL) ^ 0xffffffff);
    printf("%ld\n",current);
}
