#include <stdio.h>
int stackoverflow(int i);

int main()
{
    //
    int i = stackoverflow(5);
    printf("i = %d\n", i);
}

int stackoverflow(int i)
{
    // if (i == 0)
    //     return i;
    static int counter = 0;
    printf("counter: %d\n", counter++);
    i = stackoverflow(i - 1);
    return i;
}
