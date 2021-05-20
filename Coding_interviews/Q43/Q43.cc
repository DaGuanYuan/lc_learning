#include <iostream>
#include <math.h>

class Solution {
public:
    int numsofOneBetween1toN(int n) {
        if (n <= 0) {printf("Invalid Input!\n");}
        int tempN = n;
        int curDigit = 0;
        int curDigitTotalNumof1 = 0;
        int curDigitNum = 0;
        int totalNumof1 = 0;
        while (tempN / 10) {
            curDigitNum = tempN % 10;
            curDigit += 1;
            // f(n) = 10f(n-1) + 10^(n-1)
            // f(n):numsof1 between 1...10^n-1
            // eg: f(3) = numsof1 between 1...999
            // f(0) = 0
            if (curDigit > 1) {curDigitTotalNumof1 = 10 * curDigitTotalNumof1 + std::pow(10, curDigit - 1);} 
            if (curDigitNum >= 1) {totalNumof1 += std::pow(10, curDigit - 1);}
            totalNumof1 += curDigitNum * curDigitTotalNumof1;
            tempN /= 10;
        }
        int lastNum = 1 * (n - tempN * std::pow(10, curDigit));
        totalNumof1 += lastNum;
        return totalNumof1;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    return 0;
}