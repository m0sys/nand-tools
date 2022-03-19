#include <stdio.h>

// This is none-trail-recur.
long rprod(long* start, long count)
{
    if (count <= 1)
        return 1;
    return *start * rprod(start + 1, count - 1);
}

int main()
{
    long arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    printf("Prod: %ld\n", rprod(&arr, 10));
}
