#include <stdio.h>
int main()
{
    //
    printf("Hello, World!");
}

void decode1(long* xp, long* yp, long* zp)
{
    // {xp : %rdi}, {yp : %rsi}, {zp : %rdx}

    long x = *xp; // movq (%rdi), %r8
    long y = *yp; // movq (%rsi), %rcx
    long z = *zp; // movq (%rdx), %rax

    *yp = x; // movq %r8, (%rsi)
    *zp = y; // movq %rcx, (%rdx)
    *xp = z; // movq %rax, (%rdxi)
}
