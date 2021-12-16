// Some casting error show down.
// Book: CSAPP: S2.2 - Int Representations

#include <stdio.h>

/* WARNING: this is no longer buggy code */
float sum_elems(float a[], unsigned len)
{
    float res = 0;

    for (int i = 0; i < len; i++)
        res += a[i];
    return res;
}

int main()
{
    float arr[3] = { 1.0, 2.0, 3.0 };
    printf("Should be 0.0: %.1f\n", sum_elems(arr, 0.0));
}
