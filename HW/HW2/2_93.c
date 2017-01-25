#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned float_bits;

/* Convert a unsigned to a float Converts without changing the bit
 * representation. A normal cast from an unsigned to a float results
 * in the bit representation changing. The number 3 as an unsigned
 * doesn't have the same representation as the number 3 as a float.
 */

float u2f(unsigned u) {
    return *((float *) &u);
}

/* Convert a float to an unsigned without changing the bit representation.
 */

unsigned f2u(float f) {
    return *((unsigned *) &f);
}


float_bits float_absval(float_bits f) {
    unsigned not_a_number = (0x7F << 24) | (0x80 << 16) | 0x01;
    unsigned abs = f & ~(0x80 << 24);

    if (abs >= not_a_number) {
        return f;
    } else {
        return abs;
    }
}


int main() {
    float_bits loop = 0;
    do {
	float f = u2f(loop);
	float my_abs = u2f(float_absval(loop));
  	// weird test because NaN != NaN
	if (((f == f) && my_abs != fabsf(f)) || !(f == f) && (my_abs == my_abs)) {
	    printf("ERROR! Input %e, your abs value = %e and c library"
		   " gives %e\n", f, my_abs, fabs(f));
	    exit(-1);
	}
	loop++;
    } while (loop);
    printf("All 2^32 values check out\n");

    // Show a few test cases that are interesting to turn in with your hw
    float f = -1;
    printf("Input: %e\n\t My abs: %e\n\t C abs: %e\n", f, u2f(float_absval(f2u(f))), fabs(f));
    f = -0xFFFFFFFF;
    printf("Input: %e\n\t My abs: %e\n\t C abs: %e\n", f, u2f(float_absval(f2u(f))), fabs(f));
    f = -0x0;
    printf("Input: %e\n\t My abs: %e\n\t C abs: %e\n", f, u2f(float_absval(f2u(f))), fabs(f));
    f = -0x000FFFFF;
    printf("Input: %e\n\t My abs: %e\n\t C abs: %e\n", f, u2f(float_absval(f2u(f))), fabs(f));
    f = 0x29834681;
    printf("Input: %e\n\t My abs: %e\n\t C abs: %e\n", f, u2f(float_absval(f2u(f))), fabs(f));

    return 0;
}
