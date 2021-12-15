#include <stdio.h>
#include <string.h>

typedef unsigned char* byte_pointer;

void test_show_bytes(int val);
void show_bytes(byte_pointer start, size_t len);
void show_int(int x);
void show_float(float x);
void show_pointer(void* x);

void problem_2_5();
void problem_2_7();

int main()
{
    //
    problem_2_5();
    printf("---------\n");
    problem_2_7();
}

void test_show_bytes(int val)
{
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
