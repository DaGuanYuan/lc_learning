#include <iostream>

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) {return x;}
        int left = 1, right = x, mid = 0;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (x / mid ==  mid) {return mid;}
            else if (x / mid < mid) {right = mid - 1;}
            else {left = mid + 1;}
        }
        return right;
    }

    int mySqrt_Solution2(int x) {
        long a = x;
        while (a * a > x) {
            a = (a + x / a) / 2;
        }
        return a;
    }
};