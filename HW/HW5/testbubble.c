#include <stdio.h>

#define SIZE 6

long array1[SIZE+1] = { 0xdddd, 0xeeee, 0xbbbb, 0xaaaa, 0xffff, 0xcccc, 0x0101 } ;
long array2[SIZE+1] = { 0xdddd, 0xeeee, 0xbbbb, 0xaaaa, 0xffff, 0xcccc, 0x0101 } ;

void bubble_a(long *data, long count)
{
    long i, last;
    for(last = count - 1; last > 0; last--) {
        for(i = 0; i < last; i++) {
            if(data[i+1] < data[i]) {
                long t = data[i+1];
                data[i+1] = data[i];
                data[i] = t;
            }
        }
    }
}

void bubble_p(long *data, long count)  /* pointer version */
{
    long i, last;
    for(last = count - 1; last > 0; last--) {
        for(i = 0; i < last; i++) {
            if(*(data + i + 1) < *(data + i)) {
                long t = *(data + i + 1);
                *(data + i + 1) = *(data + i);
                *(data + i) = t;
            }
        }
    }
}

int main()
{
    int i;

    printf("array version\n");
    printf("  Before: ");
    for (i = 0; i < SIZE; i++)
	printf("0x%.4x ", array1[i]);
    printf("\n");
    bubble_a(array1, SIZE);
    printf("  After:  ");
    for (i = 0; i < SIZE; i++)
	printf("0x%.4x ", array1[i]);
    printf("\n");

    printf("pointer version\n");
    printf("  Before: ");
    for (i = 0; i < SIZE; i++)
	printf("0x%.4x ", array2[i]);
    printf("\n");
    bubble_p(array2, SIZE);
    printf("  After:  ");
    for (i = 0; i < SIZE; i++)
	printf("0x%.4x ", array2[i]);
    printf("\n");
}
