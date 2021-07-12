#include <iostream>
#include <vector>

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {return n;}
        std::vector<int> dp(n + 1, 1);
        int maxLen = 1;
        for (int i = 2; i <= n; ++i) {
            for (int k = 1; k < i; ++k) {
                if (nums[i - 1] <= nums[i - k - 1]) {continue;}
                dp[i] = std::max(dp[i], dp[i - k] + 1);
                maxLen = std::max(maxLen, dp[i]);
            }
        }
        return maxLen;
    }
};