#include <iostream>
#include <vector>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {return 0;}
        if (n == 1) {return nums[0];}
        std::vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 2; i <= n; ++i) {
            dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        return dp[n];

        // std::vector<int> dp(n, 0);
        // dp[0] = nums[0];
        // dp[1] = std::max(nums[1], nums[0]);
        // for (int i = 2; i < n; ++i) {
        //     dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
        // }
        // return dp[n - 1];
    }    

    


    int rob_withCompression(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {return 0;}
        if (n == 1) {return nums[0];}
        int pre2 = nums[0];
        int pre1 = std::max(nums[0], nums[1]);
        int cur = pre1;
        for (int i = 2; i < n; ++i) {
            cur = std::max(nums[i] + pre2, pre1);
            pre2 = pre1;
            pre1 = cur;
        }
        return cur;
    }
};