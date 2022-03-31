/* Rearrange two vects so that for each i, b[i] >= a[i] */
void minmax1(long a[], long b[], long n)
{
    // More "imperative" style
    long i;
    for (i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            long t = a[i];
            a[i] = b[i];
            b[i] = t;
        }
    }
}

/* Rearrange two vects so that for each i, b[i] >= a[i] */
void minmax2(long a[], long b[], long n)
{
    // More "functional" style
    long i;
    for (i = 0; i < n; i++) {
        long min = a[i] < b[i] ? a[i] : b[i];
        long max = a[i] < b[i] ? b[i] : a[i];

        a[i] = min;
        b[i] = max;
    }
}
