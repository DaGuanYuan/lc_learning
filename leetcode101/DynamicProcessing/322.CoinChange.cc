#include <iostream>
#include <vector>

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        int N = coins.size();
        if (N <= 0 || amount < 0) {return -1;}
        if (amount == 0) {return 0;}
        std::vector<int> dp(amount + 1, INT32_MAX - 1);
        dp[0] = 0;
        for (int i = 0; i < N; ++i) {
            int coin = coins[i];
            for (int j = coin; j <= amount; ++j) {
                dp[j] = std::min(dp[j], dp[j - coin] + 1);
            }
        }
        if (dp[amount] == INT32_MAX - 1) {return -1;}
        else {return dp[amount];}
    }
};