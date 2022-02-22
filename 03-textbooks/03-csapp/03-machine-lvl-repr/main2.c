#include <stdio.h>

long exch(long* xp, long y);

int main()
{
    long a = 10;
    long b = 20;
    long c = exch(&a, b);
    printf("a=%ld, b=%ld, c=%ld", a, b, c);
}
