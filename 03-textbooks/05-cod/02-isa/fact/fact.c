// Author: m0sys
// Date: 2022/7/21

#include <stdio.h>
long long int fact(long long int n)
{

    if (n < 1)
        return 1;
    else
        return (n * fact(n - 1));
}

int main()
{
    printf("Hello, World!\n");
    printf("fact(5) = %lld\n", fact(5));
}
