#include <stdio.h>

void iter_me_timber();
void shift_more_than_bits();
void sub_small_unsigned_from_big_unsigned();
void get_bits();

int main()
{
    //
    // sub_small_unsigned_from_big_unsigned();
    get_bits();
}

void shift_more_than_bits()
{
    int lval = 0xFEDCBA98 << 32;
    int aval = 0xFEDCBA98 >> 36;
    unsigned uval = 0xFEDCBA98u >> 40;

    printf("lval=%d; aval=%d; uval=%d\n", lval, aval, uval);
}

void iter_me_timber()
{
    // NOTE: since ++i, i++ are not being used in assignement they make no diff
    //       when used in for loop.
    //
    //       In assignement ++i will first increment and store value in lhs, while
    //       i++ will first store curr value in lhs then inc i.

    int niter = 10;
    printf("i++ iter && i < niter: \n");
    for (int i = 0; i < niter; i++) {
        printf(" %d", i);
    }
    // printf("\noutput should be: %d %d %d %d %d %d %d %d %d %d", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);

    printf("\ni++ iter && i <= niter: \n");
    for (int i = 0; i <= niter; i++) {
        printf(" %d", i);
    }
    // printf("\noutput should be: %d %d %d %d %d %d %d %d %d", 0, 1, 2, 3, 4, 5, 6, 7, 8);

    printf("\n++i iter && i < niter: \n");
    for (int i = 0; i < niter; ++i) {
        printf(" %d", i);
    }
    // printf("\noutput should be: %d %d %d %d %d %d %d %d %d", 0, 1, 2, 3, 4, 5, 6, 7, 8);

    printf("\n++i iter && i <= niter: \n");
    for (int i = 0; i <= niter; ++i) {
        printf(" %d", i);
    }
    // printf("\noutput should be: %d %d %d %d %d %d %d %d %d %d", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
}

void sub_small_unsigned_from_big_unsigned()
{
    // Conclusion: what really happens is 2^w - small.

    // unsigned long small = 0x1111;
    // unsigned long big = 0x11111;
    unsigned long small = 15;
    unsigned long big = 31;
    printf("small=%lu; big=%lu: ", small, big);
    printf("small - big(unsigned long): %lu\n", (small - big));
    printf("big - small(unsigned long): %lu\n", (big - small));

    // size_t small2 = 0x1111;
    // size_t big2 = 0x11111;
    size_t small2 = 15;
    size_t big2 = 31;
    printf("small2=%zu; big2=%zu: ", small2, big2);
    printf("small - big(size_t): %zu\n", (small2 - big2));
    printf("big - small(size_t): %zu\n", (big2 - small2));
}

void get_bits()
{
    unsigned a = 32;
    printf("%d\n", ((a << 2) >> 2));
}
