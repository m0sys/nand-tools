#include <stdio.h>

int main()
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
