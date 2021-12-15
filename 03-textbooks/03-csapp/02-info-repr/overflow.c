#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int main()
{
    int i = 200 * 300 * 400 * 500;
    int64_t i2 = 200 * 300 * 400 * 500;
    uint64_t i3 = 200 * 300 * 400 * 500;
    printf("Overflow: %d\n", i);
    printf("Still Overflow(int64): %" PRId64 "\n", i2);
    printf("Still Overflow(uint64): %" PRId64 "\n", i3);
}
