#include <iostream>
#include <vector>

class Solution {
public:
    int climeStairs(int n) {
        if (n <= 2) {return n;}
        std::vector<int> dp(n + 1, 0);
        dp[0] = 1, dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    int climbStairs_withCompression(int n) {
        if (n <= 1) {return n;}
        int pre1 = 1, pre2 = 1, cur = 0, steps= n - 1;
        while (steps--) {
            cur = pre1 + pre2;
            pre2 = pre1;
            pre1 = cur;
        }
        return cur;
    }
};