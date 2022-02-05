#include <stdio.h>

int bis(int x, int m);
int bic(int x, int m);
int int2bin(int x);
int bool_or(int x, int y);
int bool_xor(int x, int y);

int main()
{
    //
    printf("0x1110 bis 0x01011: %d\n", bis(14, 11));
    printf("0x1001 bis 0x0110: %d\n", bis(9, 6));
    printf("0x0001 bis 0x0110: %d\n", bis(1, 6));

    printf("0x1110 bic 0x01011: %d\n", bic(14, 11));
    printf("0x1001 bic 0x0110: %d\n", bic(9, 6));
    printf("0x0001 bic 0x0110: %d\n", bic(1, 6));

    printf("0x1110 bool_or 0x01011: %d\n", bool_or(14, 11));
    printf("0x1110 | 0x01011: %d\n", 14 | 11);
    printf("0x1110 bool_xor 0x01011: %d\n", bool_xor(14, 11));
    printf("0x1110 ^ 0x01011: %d\n", 14 ^ 11);
    printf("25 bool_xor 8: %d\n", bool_xor(25, 8));
    printf("25 ^ 8: %d\n", 25 ^ 8);
}

int bis(int x, int m)
{
    int m_bin = int2bin(m);
    int res = x;
    // printf("m_bin at begin: %d\n", m_bin);
    // printf("res at begin: %d\n", res);

    int counter = 0;
    while (m_bin != 0) {
        int bit = m_bin % 10;
        // printf("(%d): bit = %d\n", counter, bit);
        if (bit == 1) {
            res |= 1U << counter;
            // printf("(%d): res = %d\n", counter, res);
        }

        m_bin /= 10;
        counter++;
    }
    return res;
}

int bic(int x, int m)
{
    int m_bin = int2bin(m);
    int res = x;

    int counter = 0;
    while (m_bin != 0) {
        int bit = m_bin % 10;
        if (bit == 1) {
            res &= ~(1U << counter);
        }

        m_bin /= 10;
        counter++;
    }
    return res;
}

// Compute x|y using bis/bic.
int bool_or(int x, int y)
{
    //
    return bis(x, y);
}

// Compute x^y using bis/bic.
int bool_xor(int x, int y)
{
    int uxy = bis(x, y);
    int kx = bic(uxy, x);
    int ky = bic(uxy, y);
    return bis(kx, ky);
}

int int2bin(int x)
{
    int q = x;
    int digit = 1;
    int res = 0;
    while (q != 0) {
        if (q % 2 != 0)
            res += digit;
        digit *= 10;
        q /= 2;
    }
    return res;
}
