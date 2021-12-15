// Very cool swaping trickery for O(1) space swapping.

#include <stdbool.h>
#include <stdio.h>

void reverse_array(int a[], int cnt);
void print_arr(int arr[], int len);

int main()
{
    int a[4] = { 1, 2, 3, 4 };
    int b[5] = { 1, 2, 3, 4, 5 };

    reverse_array(a, 4);
    print_arr(a, 4);

    printf("Original b: ");
    print_arr(b, 5);
    reverse_array(b, 5);
    printf("Reversed b: ");
    print_arr(b, 5);
}

void inplace_swap(int* x, int* y)
{
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}

void reverse_array(int a[], int cnt)
{
    int first, last;
    bool is_odd = cnt % 2 == 1;
    for (first = 0, last = cnt - 1; first <= last; first++, last--) {
        if (is_odd && first == last)
            continue;
        inplace_swap(&a[first], &a[last]);
    }
}

void print_arr(int arr[], int len)
{
    for (int i = 0; i < len; i++)
        printf(" %d", arr[i]);
    putchar('\n');
}
