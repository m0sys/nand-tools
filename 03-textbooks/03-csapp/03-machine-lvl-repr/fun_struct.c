#include <stdio.h>

struct rec {
    int i;
    int j;
    int a[2];
    int* p;
};

int main()
{
    int a = 0;
    struct rec r;
    r.i = 20;
    r.j = 40;
    r.a[0] = 1;
    r.a[1] = 2;
    r.p = &a;

    printf("i: %d\n", r.i);
}
