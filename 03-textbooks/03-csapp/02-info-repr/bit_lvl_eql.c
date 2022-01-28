#include <stdio.h>

int eql(int a, int y);

int main()
{
    printf("is 1 == 1?: %d\n", eql(1, 1));
    printf("is 1 == 2?: %d\n", eql(1, 2));
    printf("is 10 == 20?: %d\n", eql(10, 20));
    printf("is 10 == 10?: %d\n", eql(10, 10));
}

int eql(int a, int y) { return !(a & ~y); }
