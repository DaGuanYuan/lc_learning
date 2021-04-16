#include <iostream>

class Solution {
public:
    int NumberofOne_solution1(int n) {
        int res = 0;
        int acceccory = 1;
        while (acceccory) {
            if (acceccory & n) {res++;}
            acceccory = acceccory << 1;
        }
        return res;
    }

    int NumberofOne_solution2(int n) {
        int res = 0;
        while (n) {
            n = n & (n - 1);
            res++;
        }
        return res;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    printf("%d\n", s.NumberofOne_solution2(0x8000000));
    return 0;
}