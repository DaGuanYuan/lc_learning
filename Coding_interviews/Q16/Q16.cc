#include <iostream>

class Solution {
public:
    int flag_invalidInput = 0;
    double PowerwithabsExponent(double base, int absExponent) {
        if (absExponent == 0) {return 1;}
        if (absExponent == 1) {return base;}
        // using res to save the recursive results
        // otherwise more time complexity occurs
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
        // Here we don't consider the minus bound where exponent = -2147483648
        // Since int ranges from -2147483648 to 2147483647, -exponent will equal
        // to 2147483648, which cannot be contained in an int variable
        // The correct solution should use string to simulate the power process
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

