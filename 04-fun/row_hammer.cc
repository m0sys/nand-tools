#include <iostream>
#define LOG(x) std::cout << x << "\n"

int main()
{
    int* ptr = new int[10];
    int counter = 0;
    while (true) {
        if (counter % 2 == 0) {

            *ptr = 0;
            LOG(counter << ": hammering a " << *ptr);
            
        }
        else {
            *ptr = 1;
            LOG(counter << ": hammering a " << *ptr);
        }
        counter++;
    }
}
