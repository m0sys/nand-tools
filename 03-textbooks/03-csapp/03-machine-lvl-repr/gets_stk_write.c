// Causing unwanted writing of return point store in stk frame.
#include <stdio.h>

char* gets(char* s)
{
    int c;
    char* dest = s;
    while ((c = getchar()) != '\n' && c != EOF)
        *dest++ = c;
    if (c == EOF && dest == s)
        return NULL;
    *dest++ = '\0';
    return s;
}

void echo()
{
    char buf[8];
    gets(buf);
    puts(buf);
}

int main()
{
    int a = 1;
    // To write over unused stack space type 9-23 chars.
    // To write over return addr type 24-31 chars.
    // To write over saved state in caller write 32+ chars.
    echo();

    printf("a: %d\n", a);
}
