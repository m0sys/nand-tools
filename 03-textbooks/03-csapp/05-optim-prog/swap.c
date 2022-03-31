#include <stdio.h>

void swap(long* xp, long* yp)
{
    // If *xp === *yp then the result is that *xp will be set to 0.
    *xp = *xp + *yp;
    *yp = *xp - *yp;
    *xp = *xp - *yp;
}

int main()
{
    long x = 5;
    swap(&x, &x);
    printf("x = %ld\n", x);
}
