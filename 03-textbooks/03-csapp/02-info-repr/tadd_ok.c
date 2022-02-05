// Book: CSAPP: S2.3 - Int Arith

#include <stdio.h>

int main() { }

int tadd_ok(int x, int y)
{
    int s = x + y;

    // Case 4 - positive overflow.
    if (x > 0 && y > 0 && s < 0)
        return 0;

    // Case 1 - negative overflow.
    if (x < 0 && y < 0 && s >= 0)
        return 0;

    return 1;
}
