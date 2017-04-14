#include "csapp.h"

void end()
{
    printf("2  ");
    printf("pid = %d\n",getpid());
    fflush(stdout);
}

int main()
{
    if(fork() == 0) {
        atexit(end);
    }
    if(fork() == 0) {
        printf("0  ");
        printf("pid = %d\n",getpid());
        fflush(stdout);
    }
    else {
        printf("1  ");
        printf("pid = %d\n",getpid());
        fflush(stdout);
    }
}
