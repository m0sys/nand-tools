#include "code_maps.h"
#include "common/prompt_input.h"

#include <iostream>
#include <map>
#include <math.h>
#include <stdexcept>
#include <string.h>

#define LOG(msg) std::cout << msg << std::endl

void dec2bin(float val);
void dec2oct(float val);
void dec2hex(float val);
void dec2radix(float val, int rad, std::map<int, char> m);
void ask_double(double& num, std::string msg);

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
    bool act_prompt = true;

    if (act_prompt) {
        LOG("Hello, and Welcome!\n");
        LOG("1) Decimal to Binary");
        LOG("2) Decimal to Octal");
        LOG("3) Decimal to Hexadecimal");

        int rad;
        prompt::ask_int(rad, "Please choose the Radix you want to convert to: ");
        LOG("");

        double decimal;
        prompt::ask_double(decimal, "Enter your decimal number: ");

        switch (rad) {
        case 1:
            dec2bin(decimal);
            break;
        case 2:
            dec2oct(decimal);
            break;
        case 3:
            dec2hex(decimal);
            break;
        default:
            LOG("Error: your choice is not valid.");
            LOG("Goodbye");
        }
    }
}

void dec2bin(float val) { dec2radix(val, 2, bin_map); };
void dec2oct(float val) { dec2radix(val, 8, oct_map); };
void dec2hex(float val) { dec2radix(val, 16, hex_map); };

void dec2radix(float val, int rad, std::map<int, char> m)
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
