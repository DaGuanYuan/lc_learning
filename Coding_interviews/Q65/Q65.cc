#include <iostream>

class Solution {
public:
    int myAdd(int a, int b) {
        while (b) {
            // In CPP, negative numbers are not allowed left shifting, since ambiguous result may occur
            int carry = static_cast<unsigned int>(a & b) << 1;
            a ^= b;
            b = carry;
        }
        return a;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    // num1 < 0, num2 < 0
    // num1 < 0, num2 = 0
    // num1 < 0, num2 > 0
    // num1 = 0, num2 = 0
    // num1 = 0, num2 > 0
    // num1 > 0, num2 > 0
    int num1 = -1;
    int num2 = 2;
    int sum = s.myAdd(num1, num2);
    printf("%d + %d = %d\n", num1, num2, sum);
    return 0;
}