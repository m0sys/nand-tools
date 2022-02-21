// Rev Eng test_two asm for PP3.28.

#include <stdio.h>

short test_two(unsigned short x)
{
    short val = 0;
    short i;
    for (i = 1; i != x; i++) {
        short tmp = x;
        tmp &= 1;
        val += val;
        val |= tmp;
        x >>= 1;
    }

    return val;
}

int main()
{
    //
    // printf("What is 0?: %d\n", test_two(0));
    // printf("What is 1?: %d\n", test_two(1));
    // printf("What is 10?: %d\n", test_two(10));
    // printf("What is 111?: %d\n", test_two(111));
    printf("What is 0? (even): %d\n", test_two(0));
    printf("What is 5? (odd): %d\n", test_two(5));
    printf("What is 6? (even): %d\n", test_two(6));
    printf("What is 13? (odd): %d\n", test_two(13));
    printf("What is 15? (odd): %d\n", test_two(15));
    printf("What is 10? (odd): %d\n", test_two(10));
    printf("What is 110? (even): %d\n", test_two(110));
}
