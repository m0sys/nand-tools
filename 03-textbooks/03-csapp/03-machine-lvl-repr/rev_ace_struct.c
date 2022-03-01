// Rev Eng ACE struct test func for PP3.42.
#include <stdio.h>

// This struct represents a single linked list.
struct ACE {
    short v;
    struct ACE* p;
};

short test(struct ACE* ptr)
{
    short res = 1;
    if (ptr) { // check for nullptr
        res *= ptr->v;
        ptr = ptr->p;
    }
    return res;
}

short test_corr(struct ACE* ptr)
{
    // This function mults over the elems in sl lst.
    short res = 1;
    while (ptr) { // nullptr check
        res *= ptr->v;
        ptr = ptr->p;
    }
    return res;
}

int main()
{
    struct ACE ll1 = { 1 };
    struct ACE ll2 = { 2 };
    struct ACE ll3 = { 3 };
    struct ACE ll4 = { 4 };
    struct ACE ll5 = { 5 };
    struct ACE ll6 = { 6 };

    ll1.p = &ll2;
    ll2.p = &ll3;
    ll3.p = &ll4;
    ll4.p = &ll5;
    ll5.p = &ll6;

    printf("SUM: %d\n", test_corr(&ll1));
}
