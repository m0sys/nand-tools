#include "code_maps.h"

#include <iostream>
#include <map>
#include <math.h>
#include <string.h>

#define LOG(msg) std::cout << msg << std::endl

void bin_to_dec(float val);
void oct_to_dec(float val);
void hex_to_dec(float val);

struct IntFrac {
    double int_part;
    double frac_part;
};

IntFrac split_float(float val);
void radix_to_dec(float val, int rad, std::map<int, char> m);

int main()
{
    //
    LOG("Hello, World!");
    LOG("n = 3.14");
    bin_to_dec(3.14);
    oct_to_dec(3.14);
    hex_to_dec(3.14);

    LOG("n = 2.71828");
    bin_to_dec(2.71828);
    oct_to_dec(2.71828);
    hex_to_dec(2.71828);
}

void bin_to_dec(float val) { radix_to_dec(val, 2, bin_map); };
void oct_to_dec(float val) { radix_to_dec(val, 8, oct_map); };
void hex_to_dec(float val) { radix_to_dec(val, 16, hex_map); };

void radix_to_dec(float val, int rad, std::map<int, char> m)
{
    using std::string;
    string int_str = "";
    string fract_str = "";

    auto splited = split_float(val);

    // Process the integer part.
    double q = splited.int_part;
    while (q != 0) {
        int rem = fmod(q, rad);
        int res = q / rad;
        q = res;
        int_str = m[rem] + int_str;
    }

    // LOG("Int Part: " << int_str);

    // Process the decimal part.
    double res = splited.frac_part;
    while (res != 0) {
        double nres = res * rad;
        splited = split_float(nres);
        int r = splited.int_part;
        res = splited.frac_part;
        fract_str += m[r];
    }
    // LOG("Frac Part: " << fract_str);

    LOG("Res(" << rad << "): " << int_str << "." << fract_str);
}

IntFrac split_float(float val)
{
    double fract, intg;

    fract = modf(val, &intg);
    return IntFrac { intg, fract };
}
