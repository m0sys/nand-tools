// Some mistery fun(c).
// Book: CSAPP: S2.2 - Int Representations

#include <stdio.h>

int fun1(unsigned word) { return (int)((word << 24) >> 24); }

int fun2(unsigned word) { return ((int)word << 24) >> 24; }

int main()
{
    printf("fun1: 0x00000076: %d\n", fun1(0x00000076));
    printf("fun2: 0x00000076: %d\n", fun2(0x00000076));

    printf("fun1: 0x87654321: %d\n", fun1(0x87654321));
    printf("fun2: 0x87654321: %d\n", fun2(0x87654321));

    printf("fun1: 0x000000C9: %d\n", fun1(0x000000C9));
    printf("fun2: 0x000000C9: %d\n", fun2(0x000000C9));

    printf("fun1: 0xEDCBA987: %d\n", fun1(0xEDCBA987));
    printf("fun2: 0xEDCBA987: %d\n", fun2(0xEDCBA987));
}
