#include <iostream>
#include <math.h>

class Solution {
public:
    int numsofOneBetween1toN(int n) {
        if (n <= 0) {return 0;}
        int totalNumsof1Between1toN = 0;
        int cur = 0;
        // in fact, considering digit could be very very large
        // so you'd better use string to simulate this process
        long long digit = 1;
        int low = 0;
        int high = 0;
        int tempN = n;
        while (tempN) {
            low += cur * (digit / 10);
            cur = tempN % 10;
            high = tempN / 10;
            if (cur == 0) {totalNumsof1Between1toN += high * digit;}
            else if (cur == 1) {totalNumsof1Between1toN += (high * digit + low + 1);}
            else {totalNumsof1Between1toN += (high + 1) * digit;}
            digit *= 10;
            tempN = high;
        }
        return totalNumsof1Between1toN;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    // n <= 0 , n = 1
    // normal
    int n = 12;
    int totalNums = s.numsofOneBetween1toN(n);
    printf("Numbers of 1 between 1 to %d is %d\n", n, totalNums);
    return 0;
}