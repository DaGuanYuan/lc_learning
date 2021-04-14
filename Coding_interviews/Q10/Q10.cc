#include <iostream>
#include <vector>

class Solution {
public:
    long long Fibonacci(unsigned int n) {
        if (n <= 0) {return 0;}
        if (n == 1) {return 1;}
        int pre = 0;
        int cur = 1;
        int next = __INT_MAX__;
        while (n >= 2) {
            next = pre + cur;
            pre = cur;
            cur = next;
            n--;
        }
        return cur;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    printf("result = %lld\n", s.Fibonacci(6));
    return 0;
}