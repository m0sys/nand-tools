// Some strlen error show down.
// Book: CSAPP: S2.2 - Int Representations

#include <stdio.h>
#include <string.h>

/* WARNING: this is no longer buggy code */
int strlonger(char* s, char* t) { return strlen(s) > strlen(t); }

int main()
{
    char str1[] = "Hello, World!";
    char str2[] = "Hello, from Clang!";

    printf("Is longer? %d\n", strlonger(str1, str2));
}
