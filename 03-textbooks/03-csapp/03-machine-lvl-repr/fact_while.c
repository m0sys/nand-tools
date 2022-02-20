// Checking out gcc -01 optimization which transforms while to do-while.
#include <stdio.h>

long fact_while(long n)
{
    long res = 1;
    while (n > 1) {
        res *= n;
        n--;
    }
    return res;
}

int main()
{
    //
    printf("14! using long64 as store: %ld\n", fact_while(14));
}
