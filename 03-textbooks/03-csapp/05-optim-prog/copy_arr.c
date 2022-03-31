// Sln to PP5.10.
#include <stdio.h>

void copy_arr(long* src, long* dest, long n)
{
    long i;
    for (i = 0; i < n; i++)
        dest[i] = src[i];
}

void print_arr(const long* src, long n)
{
    for (int i = 0; i < n; i++)
        printf("(%d): %ld, ", i, src[i]);
    printf("\n");
}

int main()
{
    const unsigned int arr_sz = 1000;
    long arr[arr_sz];
    for (int i = 0; i < arr_sz; i++)
        arr[i] = i;

    // A. this would shift all elems to the left by 1.
    // No load dependence.
    copy_arr(arr + 1, arr, arr_sz - 1);
    print_arr(arr, arr_sz);

    // Reset arr.
    for (int i = 0; i < arr_sz; i++)
        arr[i] = i;

    // B. this will make all elems equal to arr[0].
    // Load dependence.
    copy_arr(arr, arr + 1, arr_sz - 1);
    print_arr(arr, arr_sz);

    // C. since the prev loop iter is writing to the next elem that will be
    //    loaded there is a data dependence between i and i+1 in B.

    // D. Same as C. False. There's no dependence between i and i+1.
}
