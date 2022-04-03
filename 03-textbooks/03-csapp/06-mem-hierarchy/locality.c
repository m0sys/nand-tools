#define M 10
#define N 3

// Here we profit from spacial locality since we have stride-1 row major access.
int sum_arr_rows(int a[M][N])
{
    int i, j, sum = 0;

    for (i = 0; i < M; i++)
        for (j = 0; j < N; j++)
            sum += a[i][j];
    return sum;
}

// Here we do not profit from spacial locality since we have stride-N col major access.
int sum_arr_cols(int a[M][N])
{
    int i, j, sum = 0;

    for (j = 0; j < N; i++)
        for (i = 0; i < M; j++)
            sum += a[i][j];
    return sum;
}

// PP 6.7
int prod_arr3d(int a[N][N][N])
{
    int i, j, k, prod = 1;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            for (k = 0; k < N; k++)
                prod *= a[i][j][k];

    return prod;
}
