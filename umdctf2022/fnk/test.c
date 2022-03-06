#include <stdio.h>
#include <unistd.h>

int main(){
    char *argv[5] = {"/bin/cat","test.c"};
    execvp(argv[0],argv);
}
