#include <iostream>
#define LOG(x) std::cout << x << "\n"

inline void clflush(volatile void *p)
{
    asm volatile ("clflush (%0)" :: "r"(p));
}

inline void mfence()
{
    asm volatile ("mfence" ::: "memory");
}

int main()
{
    int* ptr = new int[10];
    int delta = 4;
    int counter = 0;
    while (true) {
        if (counter % 2 == 0) {

            *ptr = 1;
            *(ptr + delta) = 0;
            LOG(counter << ": hammering a " << *ptr);
            
        }
        else {
            *ptr = 0;
            *(ptr + delta) = 1;
            LOG(counter << ": hammering a " << *ptr);
        }
        clflush(ptr);
        clflush(ptr+delta);
        mfence();
        counter++;
    }
}
