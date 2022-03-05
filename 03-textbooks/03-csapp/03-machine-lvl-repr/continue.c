void while_sum_wrong()
{
    long sum = 0;
    long i = 0;
    while (i < 10) {
        if (i & 1)
            continue;

        sum += i;
        i++;
    }
}

void while_sum_correct()
{
    long sum = 0;
    long i = 0;
    while (i < 10) {
        if (i & 1)
            i++; // or goto update
        continue;

        sum += i;
        // update
        i++;
    }
}
