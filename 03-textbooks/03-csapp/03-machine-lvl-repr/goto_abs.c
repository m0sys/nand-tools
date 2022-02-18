// Goto Code for PP3.17.

long lt_cnt = 0;
long ge_cnt = 0;

long gotodiff_se(long x, long y)
{
    // This version would be more easier to understand since it avoids
    // negating the cond. So a reason to prefer this version instead is for
    // readability.
    long result;
    int t = x >= y;
    if (t) {
        goto x_ge_y;
        lt_cnt++;
        result = y - x;
        goto done;
    }

x_ge_y:
    ge_cnt++;
    result = x - y;

done:
    return result;
}
