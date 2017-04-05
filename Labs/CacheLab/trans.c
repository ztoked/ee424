/*
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1KB direct mapped cache with a block size of 32 bytes.
 */
#include <stdio.h>
#include "cachelab.h"

int is_transpose(int M, int N, int A[N][M], int B[M][N]);
void transpose_32x32(int M, int N, int A[N][M], int B[M][N]);
void transpose_64x64(int M, int N, int A[N][M], int B[M][N]);
void transpose_61x67(int M, int N, int A[N][M], int B[M][N]);

/*
 * transpose_submit - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded.
 */
char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N])
{
    switch (N) {
    case 32:
        transpose_32x32(M, N, A, B);
        break;
    case 64:
        transpose_64x64(M, N, A, B);
        break;
    case 67:
        transpose_61x67(M, N, A, B);
        break;
    }
}

/*
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started.
 */

/*
 * trans - A simple baseline transpose function, not optimized for the cache.
 */
char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, tmp;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    }

}

void transpose_32x32(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, kk, jj;
    int bsize = 8;
    int diagVal;
    int diagIndex;
    for (kk = 0; kk < M; kk += bsize) {
        for (jj = 0; jj < N; jj += bsize) {
            for (i = jj; i < jj + bsize; ++i) {
                for (j = kk; j < kk + bsize; ++j) {
                    if (i != j) {
                        B[j][i] = A[i][j];
                    }
                    else {
                        diagVal = A[i][j];
                        diagIndex = i;
                    }
                }
                if (kk == jj) {
                    B[diagIndex][diagIndex] = diagVal;
                }
            }
        }
    }
}

void transpose_64x64(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, k, temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8;
    for(i = 0; i < 64; i += 8) {
        for(j = 0; j < 64; j += 8) {
            for(k = 0; k < 4; k++) {
                temp1 = A[i + k][j + 0];
                temp2 = A[i + k][j + 1];
                temp3 = A[i + k][j + 2];
                temp4 = A[i + k][j + 3];
                temp5 = A[i + k][j + 4];
                temp6 = A[i + k][j + 5];
                temp7 = A[i + k][j + 6];
                temp8 = A[i + k][j + 7];
                B[j + 0][i + k + 0] = temp1;
                B[j + 0][i + k + 4] = temp6;
                B[j + 1][i + k + 0] = temp2;
                B[j + 1][i + k + 4] = temp7;
                B[j + 2][i + k + 0] = temp3;
                B[j + 2][i + k + 4] = temp8;
                B[j + 3][i + k + 0] = temp4;
                B[j + 3][i + k + 4] = temp5;
            }

            temp1 = A[i + 4][j + 4];
            temp2 = A[i + 5][j + 4];
            temp3 = A[i + 6][j + 4];
            temp4 = A[i + 7][j + 4];
            temp5 = A[i + 4][j + 3];
            temp6 = A[i + 5][j + 3];
            temp7 = A[i + 6][j + 3];
            temp8 = A[i + 7][j + 3];

            B[j + 4][i + 0] = B[j + 3][i + 4];
            B[j + 4][i + 4] = temp1;
            B[j + 3][i + 4] = temp5;
            B[j + 4][i + 1] = B[j + 3][i + 5];
            B[j + 4][i + 5] = temp2;
            B[j + 3][i + 5] = temp6;
            B[j + 4][i + 2] = B[j + 3][i + 6];
            B[j + 4][i + 6] = temp3;
            B[j + 3][i + 6] = temp7;
            B[j + 4][i + 3] = B[j + 3][i + 7];
            B[j + 4][i + 7] = temp4;
            B[j + 3][i + 7] = temp8;

            for(k = 0; k < 3; k++){
                temp1 = A[i + 4][j + 5 + k];
                temp2 = A[i + 5][j + 5 + k];
                temp3 = A[i + 6][j + 5 + k];
                temp4 = A[i + 7][j + 5 + k];
                temp5 = A[i + 4][j + k];
                temp6 = A[i + 5][j + k];
                temp7 = A[i + 6][j + k];
                temp8 = A[i + 7][j + k];

                B[j + 5 + k][i] = B[j + k][i + 4];
                B[j + 5 + k][i + 4] = temp1;
                B[j + k][i + 4] = temp5;
                B[j + 5 + k][i + 1] = B[j + k][i + 5];
                B[j + 5 + k][i + 5] = temp2;
                B[j + k][i + 5] = temp6;
                B[j + 5 + k][i + 2] = B[j + k][i + 6];
                B[j + 5 + k][i + 6] = temp3;
                B[j + k][i + 6] = temp7;
                B[j + 5 + k][i + 3] = B[j + k][i + 7];
                B[j + 5 + k][i + 7] = temp4;
                B[j + k][i + 7] = temp8;
            }
        }
    }
}

void transpose_61x67(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, kk, jj;
    int temp;
    int bBig = 16;
    int bSmall = 4;
    for(kk = 0; kk < N; kk += bBig) {
        for(jj = 0; jj < M; jj += bSmall) {
            for(i = kk; (i < kk + bBig) && (i < N); ++i) {
                for(j = jj; (j < jj + bSmall) && (j < M); ++j) {
                    if (i - kk != j - jj) {
                        B[j][i] = A[i][j];
                    }
                    else {
                        temp = A[i][j];
                    }
                }
                for (j = jj; (j < jj + bSmall) && (j < M); ++j) {
                    if (i - kk == j - jj) {
                        B[j][i] = temp;
                    }
                }
            }
        }
    }
}

/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions()
{
    /* Register your solution function */
    registerTransFunction(transpose_submit, transpose_submit_desc);

    /* Register any additional transpose functions */
    registerTransFunction(trans, trans_desc);

}

/*
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; ++j) {
            if (A[i][j] != B[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}
