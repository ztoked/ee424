#include <stdio.h>
#define M 4
//typedef int Marray_t[M][M];

void print_matrix(long A[M][M]) {
	long i,j;
	for (i = 0; i < M; i++) {
		for (j = 0; j < M; j++) {
			printf("%8d   ", A[i][j]);
		}
		printf("\n");
	}
}

void transpose(long A[M][M]) {
	long i, j;
	for(i = 0; i < M; i++) {
		for (j = 0; j < i; j++) {
			long t = A[i][j];
			A[i][j] = A[j][i];
			A[j][i] = t;
		}
	}
}

void transpose_optimized(long A[M][M]) {
	// fill your code in here
    long *i = &A[0][0];
    long *j = &A[0][0];
    while(i < &A[M-1][M]) {
        long temp1 = *i;
        long temp2 = *j;
        *(i) = temp2;
        *(j) = temp1;
        j += 8;
        i += 8 * M;
    }
}

int main() {
	long i, j;
	long A[M][M] = {{1,2,3,4},{1,2,3,4},{1,2,3,4},{1,2,3,4}};
	print_matrix(A);
	printf("\n");
	//transpose(A);
	transpose_optimized(A);
	print_matrix(A);
}
