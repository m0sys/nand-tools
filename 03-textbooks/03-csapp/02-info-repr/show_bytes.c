#include <stdio.h>
#include <string.h>

typedef unsigned char* byte_pointer;

void test_show_bytes(int val);
void show_bytes(byte_pointer start, size_t len);
void show_int(int x);
void show_float(float x);
void show_pointer(void* x);

void test_show_bytes_bin(int val);
void show_bytes_bin(byte_pointer start, size_t len);
void show_int_bin(int x);
void show_float_bin(float x);
void show_pointer_bin(void* x);

void problem_2_5();
void problem_2_7();

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte) (byte & 0x80 ? '1' : '0'), (byte & 0x40 ? '1' : '0'), (byte & 0x20 ? '1' : '0'), (byte & 0x10 ? '1' : '0'), (byte & 0x08 ? '1' : '0'), (byte & 0x04 ? '1' : '0'), (byte & 0x02 ? '1' : '0'), (byte & 0x01 ? '1' : '0')

int main()
{
    //
    // problem_2_5();
    // printf("---------\n");
    test_show_bytes(10);
    test_show_bytes_bin(10);

    problem_2_7();
}

void test_show_bytes(int val)
{
    printf("Printing HEX: \n");
    int ival = val;
    float fval = (float)ival;
    int* pval = &ival;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}

void show_bytes(byte_pointer start, size_t len)
{
    for (int i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

void show_int(int x)
{
    //
    show_bytes((byte_pointer)&x, sizeof(int));
}

void show_float(float x)
{
    //
    show_bytes((byte_pointer)&x, sizeof(float));
}

void show_pointer(void* x)
{
    //
    show_bytes((byte_pointer)&x, sizeof(void*));
}

// Binary formate printing.

void test_show_bytes_bin(int val)
{
    printf("Printing BINARY: \n");
    int ival = val;
    float fval = (float)ival;
    int* pval = &ival;
    show_int_bin(ival);
    show_float_bin(fval);
    show_pointer_bin(pval);
}

void show_bytes_bin(byte_pointer start, size_t len)
{
    for (int i = 0; i < len; i++)
        printf(" " BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(start[i]));
    printf("\n");
}

void show_int_bin(int x)
{
    //
    show_bytes_bin((byte_pointer)&x, sizeof(int));
}

void show_float_bin(float x)
{
    //
    show_bytes_bin((byte_pointer)&x, sizeof(float));
}

void show_pointer_bin(void* x)
{
    //
    show_bytes_bin((byte_pointer)&x, sizeof(void*));
}

// Problem 2.5
void problem_2_5()
{
    int a = 0x12345678;
    byte_pointer ap = (byte_pointer)&a;
    show_bytes(ap, 1);
    show_bytes(ap, 2);
    show_bytes(ap, 3);
}

// Problem 2.7
void problem_2_7()
{
    const char* m = "mnopqr";
    show_bytes((byte_pointer)m, strlen(m));
}
