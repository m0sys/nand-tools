// Factorial 14 comp for PP3.22.
#include <stdint.h>
#include <stdio.h>

int32_t fact_do_goto32(int n)
{
    int32_t res = 1;
loop:
    res *= n;
    n--;
    if (n > 1)
        goto loop;

    return res;
}

long fact_do_goto64(int n)
{
    long res = 1;
loop:
    res *= n;
    n--;
    if (n > 1)
        goto loop;

    return res;
}

int main()
{
    // This code will result in overflow since 14! cannot fit into 32bit int.
    printf("14! using int32 as store: %d\n", fact_do_goto32(14));
    printf("14! using long64 as store: %ld\n", fact_do_goto64(14));
}
