#include "csapp.h"
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int file = open("hello.txt", O_RDWR);
    if (file < 0) {
        perror("hello.txt open"); exit(EXIT_FAILURE);
    }

    struct stat mystat;
    if (fstat(file, &mystat)) {
        perror("fstat"); exit(EXIT_FAILURE);
    }

    off_t myfsz = mystat.st_size;
    void*ad = mmap(NULL, myfsz, PROT_READ|PROT_WRITE, MAP_SHARED, file, 0);
    if (ad == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    if(*((char *)ad) == 'H') {
        (*(char *)ad) = 'J';
    }

}
