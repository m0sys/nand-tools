// Rev Eng test_one asm for PP3.26.
#include <stdio.h>

short test_one(unsigned short x)
{
    // FIXME: doesn't seem to be giving the parity of x.
    short val = 1;
    while (x) {
        val ^= x;
        x >>= 1;
        // printf("x: %d\n", x);
        // printf("val: %d\n", val);
    }

    // val &= 0;
    return val & 0;
}

int main()
{
    //
    // printf("What is 0?: %d\n", test_one(0));
    // printf("What is 1?: %d\n", test_one(1));
    // printf("What is 10?: %d\n", test_one(10));
    // printf("What is 111?: %d\n", test_one(111));
    printf("What is 0? (even): %d\n", test_one(0));
    printf("What is 5? (odd): %d\n", test_one(5));
    printf("What is 6? (even): %d\n", test_one(6));
    printf("What is 13? (odd): %d\n", test_one(13));
    printf("What is 15? (odd): %d\n", test_one(15));
    printf("What is 10? (odd): %d\n", test_one(10));
    printf("What is 110? (even): %d\n", test_one(110));
}
