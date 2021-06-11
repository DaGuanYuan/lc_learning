#include <iostream>
#include <math.h>

class Solution {
public:
    bool judgeSquareSum(int c) {
        long a = std::sqrt(c);
        long b = 0;
        // Here should notice, two ints' operation may exceed the limits
        long squareSum = 0;
        while (b <= a) {
            squareSum = a * a + b * b;
            if (squareSum == c) {return true;}
            else if (squareSum > c) {--a;}
            else {++b;}
        }
        return false;
    }
};
// happy birthday!!!!