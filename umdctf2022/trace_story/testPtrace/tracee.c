// Code is taken from https://www.linuxjournal.com/article/6210 (and modified)
#include <stdio.h>
#include <unistd.h>

int main()
{   int i;
    printf("%d\n",getpid());
    for(i = 0;i < 10; ++i) {
        printf("My counter: %d\n", i);
        sleep(2);
    }
    return 0;
}
