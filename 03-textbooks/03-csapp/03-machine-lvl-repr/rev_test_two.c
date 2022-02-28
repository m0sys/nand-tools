// Rev Eng test_two asm for PP3.28.

#include <stdio.h>

short test_two(unsigned short x)
{
    // B. Not sure.
    short val = 0;
    short i;
    for (i = 1; i != x; i++) {
        unsigned long long tmp = (unsigned long long)x;
        tmp &= 1;
        val += (long long)val;
        val |= tmp;
        x >>= 1;
    }

    return val;
}

long test_two_sln(unsigned short x)
{
    // Somehow the 'short' became a 'long'.
    // Mixed up val & i.
    // The question probably has some typos.
    //
    // B. The compiler gets that since i = 64 initially it cannot be equal to
    //    0. So it doesn't need a if to check init cond.
    long val = 0;
    long i;
    // Not sure how 'i--'.
    for (i = 64; i != 0; i--) {
        // '(val << 1)' is the same as 2v which is the same as addq val val.
        val = (val << 1) | (x & 0x1);
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
    printf("What is 0? (even):   %ld\n", test_two_sln(0));
    printf("What is 5? (odd):    %ld\n", test_two_sln(5));
    printf("What is 6? (even):   %ld\n", test_two_sln(6));
    printf("What is 13? (odd):   %ld\n", test_two_sln(13));
    printf("What is 15? (odd):   %ld\n", test_two_sln(15));
    printf("What is 10? (odd):   %ld\n", test_two_sln(10));
    printf("What is 110? (even): %ld\n", test_two_sln(110));
}
