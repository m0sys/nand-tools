#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int amt = pow(2, 30);
    int* p1 = malloc(amt * sizeof(int));
    printf("Malloc %ld bits of memory\n", amt * sizeof(int));

    for (int i = 0; i < amt; i++)
        *(p1 + i) = i;
    // free(p1);
    while (1)
        continue;
}
