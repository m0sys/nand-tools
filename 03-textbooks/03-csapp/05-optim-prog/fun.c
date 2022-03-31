#include <stdio.h>
int main()
{
    int x[] = { 1, 2, 3, 4, 5 };
    printf("Num elems: %ld\n", sizeof(x) / sizeof(x[0]));
}
