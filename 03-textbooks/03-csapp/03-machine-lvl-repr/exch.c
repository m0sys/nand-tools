long exch(long* xp, long y)
{
    long x = *xp;
    *xp = y;
    return x;
}
