#include <stdio.h>

int main()
{
    int count = 0;
    double f,g;
    f = 0.0;
    g = f + 1.0;
    while (f != g)
    {
        f = g;
        g = f + 1.0;
        count++;
    }
    printf("Does it ever get here? Count = %d\n", count);
    return 0;
}
