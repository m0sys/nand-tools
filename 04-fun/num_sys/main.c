#include <stdio.h>

long comp9(long num);
long comp10(long num);

int main()
{
    printf("9C(25478036) = %ld\n", comp9(25478036));
    printf("10C(25478036) = %ld\n", comp10(25478036));
    printf("9C(63325600) = %ld\n", comp9(63325600));
    printf("10C(63325600) = %ld\n", comp10(63325600));
}
