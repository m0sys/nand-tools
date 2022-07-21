// Author: m0sys
// Date: 2022/7/21

#include <stdio.h>

int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    return fib(n - 1) + fib(n - 2);
}

int main()
{
    printf("Hello, World!\n");
    printf("fib(5) = %d\n", fib(5));
}
