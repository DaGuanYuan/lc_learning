#include <iostream>
#include <math.h>

class Solution {
public:
    int digitalAtIndex(int index) {
        if (index < 0) {return -1;}
        long long digitNums = 0;
        int tempIndex = index;
        int digit = 1;
        while (1) {
            digitNums = 9 * digit * std::pow(10, digit - 1);
            if (tempIndex > digitNums) {
                tempIndex -= digitNums;
                digit++;
            }
            else {break;}
        }
        tempIndex -= 1; //start from ONE integer
        int startNum = std::pow(10, digit - 1) + tempIndex / digit;
        int pos = digit - tempIndex % digit;
        while (pos - 1) {
            startNum /= 10;
            pos--;
        }
        return startNum % 10;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    // index <= 0
    // boundary: 1, 9, 180
    // normal
    int index = 19;
    printf("The digit num at %d is: %d\n", index, s.digitalAtIndex(index));
    return 0;
}