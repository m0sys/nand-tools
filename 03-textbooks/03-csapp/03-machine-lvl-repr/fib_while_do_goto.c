// While loop and goto code for fib PP3.27
#include <stdio.h>

int fib_rec(int n);

// Prints out fib from 0 to n.
void fib(int n)
{
    int i = 0;
    int term = n + 1;
    while (i < term) {
        printf("Fib(%d): %d\n", i, fib_rec(i));
        i++;
    }
}

void fib_guarded_do_goto(int n)
{
    int i = 0;
    int term = n + 1;
    int t = i > term;

    if (t)
        goto done;

loop:
    printf("Fib(%d): %d\n", i, fib_rec(i));
    i++;
    if (i < term)
        goto loop;

done:
    return;
}

int fib_rec(int n)
{
    if (n == 0 || n == 1)
        return n;

    return fib_rec(n - 1) + fib_rec(n - 2);
}

int main()
{
    //
    fib(10);
    fib_guarded_do_goto(10);
}
