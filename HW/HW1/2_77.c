#include <stdio.h>

int main(void)
{
    /* We are to write C expressions that multiply integer variable x
       by various values of K using only +, -, and << operators, and
       no more than 3 operators total. */

    int x = 10;
    int K;
    int result1;
    int result2;
    
    /* Example: K = 9 */
    K = 9;
    result1 = (x << 3) + x;  /* you create expressions like this one */
    result2 = K * x;         /* compute using multiply to compare */
    printf("K=9: +-<< result = %d, * result = %d\n", result1, result2);
    if(result1 != result2) {
        printf("Example 1 is INCORRECT!\n");
    }
    
    /* Part A */
    K = 17;
    result1 = (x << 4) + x;   /* replace this 0 with your C expression */
    result2 = K * x;
    printf("K=17: +-<< result = %d, * result = %d\n", result1, result2);
    if(result1 != result2) {
        printf("Example 2 is INCORRECT!\n");
    }
    
    /* Part B */
    K = -7;
    result1 = 0 - (x << 3) + x;   /* replace this 0 with your C expression */
    result2 = K * x;
    printf("K=-7: +-<< result = %d, * result = %d\n", result1, result2);
    if(result1 != result2) {
        printf("Example 3 is INCORRECT!\n");
    }
    
    /* Part C */
    K = 60;
    result1 = (x << 6) - (x << 2);   /* replace this 0 with your C expression */
    result2 = K * x;
    printf("K=60: +-<< result = %d, * result = %d\n", result1, result2);
    if(result1 != result2) {
        printf("Example 4 is INCORRECT!\n");
    }
    
    /* Part D */
    K = -112;
    result1 = 0 - (x << 7) + (x << 4);   /* replace this 0 with your C expression */
    result2 = K * x;
    printf("K=-112: +-<< result = %d, * result = %d\n", result1, result2);
    if(result1 != result2) {
        printf("Example 5 is INCORRECT!\n");
    }
}

    
    
