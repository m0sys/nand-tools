// Goto Code for PP3.16.

void cond(short a, short* p)
{

    // The reason why the asm has two jumps rather than one is because
    // in asm you don't have compound conditions such as A && B. Hence,
    // you have to check each cond separately.

    if (!a && *p >= a) {
        goto done;
        *p = a;
        return;
    }

done:
    return;
}
