// CS:APP: Practice Problem Slns for S2 - Information Representations
// Book: CSAPP - Computer Systems - A Programmer's Perspective

#include <inttypes.h>
#include <stdio.h>

// Decls
void tadd_ok_test();
void test_212();

int main()
{
    // tadd_ok_test();
    test_212();
}

// PP 2.12

int get_lsbyte(int val) { return val & 0xff; }

int comp_but_lsbyte(int val) { return (~val & ~0xff) | get_lsbyte(val); }

int ff_lsbyte(int val) { return (val & ~0xff) | 0xff; }

void test_212()
{
    //
    int val = 0x87654321;
    printf("LSB: %x\n", get_lsbyte(val));
    printf("COMP BUT LSB: %x\n", comp_but_lsbyte(val));
    printf("FF LSB: %x\n", ff_lsbyte(val));
}

// S2.3.2 - Two's-Complement Addition

/* PP 2.30 */
int tadd_ok(signed x, signed y)
{
    // For some insane reason there is no decltype in C. So none-general sln.
    int8_t s = x + y;

    // Negative Overflow.
    if (x < 0 && y < 0 && s > 0)
        return 0;

    // Positive Overflow
    if (x > 0 && y > 0 && s < 0)
        return 0;

    // Case 2 & 3.
    return 1;
}

void tadd_ok_test()
{
    // Case 1 test.
    int8_t x1 = -126;
    int8_t y1 = -3;

    // Case 2 test.
    int8_t x2 = 121;
    int8_t y2 = 6;

    // Case 3 test.
    int8_t x3 = -126;
    int8_t y3 = 2;

    // Case 4 test.
    int8_t x4 = 121;
    int8_t y4 = 7;

    printf("Case 1 ok? %d (should be false)\n", tadd_ok(x1, y1));
    printf("Case 2 ok? %d (should be true)\n", tadd_ok(x2, y2));
    printf("Case 3 ok? %d (should be true)\n", tadd_ok(x3, y3));
    printf("Case 4 ok? %d (should be false)\n", tadd_ok(x4, y4));
}
