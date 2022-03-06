// Code taken from https://www.linuxjournal.com/article/6100 (and modified)

#include <stdio.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
                          
int main()
{   pid_t child;
    long orig_eax;
    int attached;
    child = fork();
    if(child == 0) {
        // Testing if no PTRACE_TRACEME ptrace is called
        while (1){
            execl("/bin/ls", "ls", NULL);
            sleep(1);
        } 
    }
    else {
        attached = ptrace(PTRACE_ATTACH,child,NULL,NULL);
        orig_eax = ptrace(PTRACE_PEEKUSER,child,44,NULL);
        printf("Attached: %d\n",attached);
        printf("The child made a system call %ld\n", orig_eax);
        ptrace(PTRACE_CONT, child, NULL, NULL);
    }

    printf("PTRACE_ATTACH = %d\n",PTRACE_ATTACH);
    printf("PTRACE_PEEKUSER = %d\n",PTRACE_PEEKUSER);
    return 0;
}
