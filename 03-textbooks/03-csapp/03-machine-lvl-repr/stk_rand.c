// Looking into stack randomization.

#include <stdio.h>

int main()
{
    long local;
    printf("local at %p\n", &local);
}
