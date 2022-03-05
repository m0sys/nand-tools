// Optimized version of fix_set_diag for PP3.40
#include <stdio.h>

#define N 16
typedef int fix_mat[N][N];

void fix_set_diag(fix_mat A, int val)
{
    long i;
    for (i = 0; i < N; i++)
        A[i][i] = val;
}

void fix_set_diag_optim(fix_mat A, int val)
{
    int* Aptr = &A[0][0];
    int* Aend = &A[N][N];
    do {
        *Aptr = val;
        Aptr += (N + 1); // add 68 to ptr i.e. [i++][i++]
    } while (Aptr != Aend);
}

// TB sln.
void fix_set_diag_opt(fix_mat A, int val)
{
    int* Abase = &A[0][0];
    long i = 0;
    long iend = N * (N + 1);
    do {
        Abase[i] = val;
        i += (N + 1);
    } while (i != iend);
}

void print_fix_mat(fix_mat A)
{

    for (size_t i = 0; i < N; i++) {

        for (size_t j = 0; j < N; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }
}

int main()
{
    fix_mat A = { { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 } };
    print_fix_mat(A);

    fix_set_diag(A, 200);
    print_fix_mat(A);

    fix_set_diag_optim(A, 300);
    print_fix_mat(A);

    fix_set_diag_opt(A, 400);
    print_fix_mat(A);
}
