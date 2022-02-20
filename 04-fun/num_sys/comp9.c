// Calcs 9's Complement.

#include <math.h>

long comp9(long num)
{
    int n = 0;
    long q = num;
    while (q != 0) {
        n += 1;
        q /= 10;
    }

    return (pow(10, n) - 1) - num;
}
