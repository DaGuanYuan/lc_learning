#include <iostream>
#include <math.h>

class Solution {
public:
    int getUglyNumber(int n) {
        if (n < 0) {return 0;}
        int pow2 = 0;
        int pow3 = 0;
        int pow5 = 0;
        int pow2PlusCondition = 0;
        int pow3PlusCondition = 0;
        int pow5PlusCondition = 0;
        int loop = 0;
        while (loop != n) {
            pow2PlusCondition = std::pow(2, pow2 + 1) * std::pow(3, pow3) * std::pow(5, pow5);
            pow3PlusCondition = std::pow(2, pow2) * std::pow(3, pow3 + 1) * std::pow(5, pow5);
            pow5PlusCondition = std::pow(2, pow2) * std::pow(3, pow3) * std::pow(5, pow5 + 1);
            if (pow2PlusCondition > pow3PlusCondition && pow2PlusCondition > pow5PlusCondition) {pow2++;}
            if (pow3PlusCondition > pow2PlusCondition && pow3PlusCondition > pow5PlusCondition) {pow3++;}
            if (pow5PlusCondition > pow3PlusCondition && pow5PlusCondition > pow3PlusCondition) {pow5++;}
            loop++;
        }
        return std::pow(2, pow2) * std::pow(3, pow3) * std::pow(5, pow5);
    }
};