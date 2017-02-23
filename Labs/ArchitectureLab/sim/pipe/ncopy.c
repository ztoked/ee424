#include <stdio.h>

typedef int word_t;

word_t src[8], dst[8];

/* $begin ncopy */
/*
 * ncopy - copy src to dst, returning number of positive ints
 * contained in src array.
 */
word_t ncopy(word_t *src, word_t *dst, word_t len)
{
    word_t count = 0;
    word_t val;

    word_t n = (len + 7) / 8;
    switch (len % 8) {
    case 0:
        do {
        *dst = *src++;
        if(*dst++ > 0) {
            count++;
        }
    case 7:
        *dst = *src++;
        if(*dst++ > 0) {
            count++;
        }
    case 6:
        *dst = *src++;
        if(*dst++ > 0) {
            count++;
        }
    case 5:
        *dst = *src++;
        if(*dst++ > 0) {
            count++;
        }
    case 4:
        *dst = *src++;
        if(*dst++ > 0) {
            count++;
        }
    case 3:
        *dst = *src++;
        if(*dst++ > 0) {
            count++;
        }
    case 2:
        *dst = *src++;
        if(*dst++ > 0) {
            count++;
        }
    case 1:
        *dst = *src++;
        if(*dst++ > 0) {
            count++;
        }
            } while (--n > 0);
    }
    return count;
}
/* $end ncopy */

int main()
{
    word_t i, count;

    for (i=0; i<8; i++)
	src[i]= i+1;
    count = ncopy(src, dst, 8);
    printf ("count=%d\n", count);
    exit(0);
}
