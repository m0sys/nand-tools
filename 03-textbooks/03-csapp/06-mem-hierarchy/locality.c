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

// PP 6.8

#define N 1000
typedef struct {
    int vel[3];
    int acc[3];
} point;

void clear1(point* p, int n)
{
    // This one has the highest spacial locality since each inner loop will have
    // to load on chunk of memory each. i.e. the first one will load in vel,
    // the second one will load acc.
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < 3; j++)
            p[i].vel[j] = 0;
        for (j = 0; j < 3; j++)
            p[i].acc[j] = 0;
    }
}

void clear2(point* p, int n)
{
    // This one has the second highest spacial locality since we only have to
    // reload vel, acc on each inner iteration.
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < 3; j++) {
            p[i].vel[j] = 0;
            p[i].acc[j] = 0;
        }
    }
}

void clear3(point* p, int n)
{
    // This one has the lowest spacial locality since p[i] has to get loaded
    // each time.
    int i, j;
    for (j = 0; j < 3; j++) {
        for (i = 0; i < n; i++)
            p[i].vel[j] = 0;
        for (j = 0; j < 3; j++)
            p[i].acc[j] = 0;
    }
}
