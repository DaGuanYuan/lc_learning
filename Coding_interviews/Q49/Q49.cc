#include <iostream>
#include <vector>
#include <math.h>

class Solution {
public:
    int getUglyNumber(int n) {
        if (n <= 0) {return 0;}
        std::vector<int> dp(n, 1);
        // a means 2 * dp[a - 1] <= dp[n - 1] so that 2 * dp[a - 1] cannot be nth ugly num
        // while 2 * dp[a] might be
        int a = 0;
        int b = 0;  // 3 * dp[b - 1] <= dp[n - 1]
        int c = 0;  // 5 * dp[c - 1] <= dp[n - 1]
        for (int i = 1; i < n; i++) {
            int uglyNumMultiple2 = dp[a] * 2;
            int uglyNumMultiple3 = dp[b] * 3;
            int uglyNumMultiple5 = dp[c] * 5;
            dp[i] = getMin(uglyNumMultiple2, uglyNumMultiple3, uglyNumMultiple5);
            // dp[:n-1] do not have repeated number
            if (dp[i] == uglyNumMultiple2) {a++;}
            if (dp[i] == uglyNumMultiple3) {b++;}
            if (dp[i] == uglyNumMultiple5) {c++;}
        }
        return dp[n - 1];
    }

    int getMin(int a, int b, int c) {
        return std::min(a, b) < c ? std::min(a, b) : c;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    // n <= 0, n = 1, n = 2, n = 3, n = 4
    // n = 1500 -> performance test
    int n = 1500;
    int UglyNum = s.getUglyNumber(n);
    printf("%dth ugly number is: %d\n", n, UglyNum);
    return 0;
}