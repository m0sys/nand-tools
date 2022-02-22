// Reverse engineered C code from ASM PP 3.10.
#include <stdio.h>

short arith3(short x, short y, short z);

int main()
{
    short res = arith3(10, 20, 30);
    printf("Res: %d\n", res);
}

short arith3(short x, short y, short z)
{
    short p1 = y | z;
    short p2 = p1 >> 9;
    short p3 = ~p2;
    short p4 = y - p3;
    return p4;
}
