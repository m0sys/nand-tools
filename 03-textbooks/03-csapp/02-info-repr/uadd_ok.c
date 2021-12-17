// Some overflow checking action.
// Book: CSAPP: S2.2 - Int Representations

#include <inttypes.h>
#include <stdio.h>

/* 2.3 - Integer Arithmrtic */

int uadd_ok(unsigned x, unsigned y) { return x + y > x; }

int main()
{
    int8_t x1 = 250u;
    int8_t y1 = 5u;

    int8_t x2 = 250u;
    int8_t y2 = 6u;

    printf("255 + 5 is ok? %d\n", uadd_ok(x1, y1));
    printf("255 + 6 is ok? %d\n", uadd_ok(x2, y2));
}
