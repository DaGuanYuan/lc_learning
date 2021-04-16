#include <iostream>

class Solution {
public:
    int flag_invalidInput = 0;
    double PowerwithabsExponent(double base, int absExponent) {
        if (absExponent == 0) {return 1;}
        if (absExponent == 1) {return base;}
        double res = PowerwithabsExponent(base, absExponent >> 1);
        res *= res;
        if (absExponent & 0x1 == 1) {res *= base;}
        return res;
    }

    double Power(double base, int exponent) {
        if (base == 0 && exponent <= 0) {
            flag_invalidInput = 1;
            return 0.0;
        }
        double res = 1.0;
        int absExponent = exponent;
        if (absExponent < 0) {absExponent = -absExponent;}
        res = PowerwithabsExponent(base, absExponent);
        if (exponent < 0) {res = 1 / res;}
        return res;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    printf("%f\n", s.Power(100.0 ,-3));
    if (s.flag_invalidInput == 1) {printf("Invalid Input\n");}
    return 0;
}

