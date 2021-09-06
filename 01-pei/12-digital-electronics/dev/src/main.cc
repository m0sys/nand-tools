#include <cmath>
#include <iostream>
#include <string>

#define LOG(x) std::cout << x << "\n"

int dec_to_bin(int decimal)
{
    using std::string;
    int counter = decimal;
    string bin = "";

    while (counter != 1 && counter != 0) {
        if (counter % 2 == 0)
            bin = "0" + bin;
        else
            bin = "1" + bin;
        counter /= 2;
    }

    if (counter == 1)
        bin = "1" + bin;
    else
        bin = "0" + bin;

    LOG(decimal << " is " << bin << " in binary!\n");
    return std::stoi(bin);
}

int bin_to_dec(int bin)
{
    int rem = bin;
    int counter = 0;
    int res = 0;

    do {
        if (rem % 10 == 1)
            res += pow(2, counter);
        counter++;
        rem /= 10;
    } while (rem != 0);

    LOG(bin << " is " << res << " in decimal!\n");
    return res;
}

int main()
{
    LOG("Hello, from Computer Engineering!");
    bin_to_dec(dec_to_bin(109));
    bin_to_dec(dec_to_bin(164));
}
