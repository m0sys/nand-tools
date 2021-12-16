#include <inttypes.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

int main()
{
    int i = 200 * 300 * 400 * 500;
    int64_t i2 = 200 * 300 * 400 * 500;
    uint64_t i3 = 200 * 300 * 400 * 500;
    uint64_t i4 = 2 * 3 * 4 * 5 * 1e2 * 1e2 * 1e2 * 1e2;
    uint64_t i5 = 100 * 100 * 100 * 100 * 100;
    uint64_t i6 = 1e64;
    uint64_t i7 = pow(2, 64);
    printf("i -> Overflow: %d\n", i);
    printf("i2 -> Still Overflow(int64): %" PRId64 "\n", i2);
    printf("i3 -> Still Overflow(uint64): %" PRId64 "\n", i3);
    printf("i4 -> No Overflow(uint64): %" PRIu64 "\n", i4);
    printf("i5 -> No Overflow(uint64): %" PRIu64 "\n", i5);
    printf("i6 -> No Overflow(uint64): %" PRIu64 "\n", i6);
    printf("i7 -> No Overflow(uint64): %" PRIu64 "\n", i7);
    printf("1e2 = %lf\n", 1e2);
}
