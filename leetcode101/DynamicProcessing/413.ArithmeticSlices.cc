#include <iostream>
#include <vector>
#include <numeric>

class Solution {
public:
    //dp means length of arithmetic subsequences 
    int numberofArithmeticSlices_S1(std::vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {return 0;}
        std::vector<int> dp(n + 1, 2);
        for (int i = 2; i <= n - 1; ++i) {
            if (nums[i - 1] - nums[i - 2] == nums[i] - nums[i - 1]) {
                dp[i + 1] = dp[i] + 1;
                dp[i] = 2;
            }
        }
        int res = 0;
        for (const int& val : dp) {
            res += (val - 1) * (val - 2) / 2;
        }
        return res;
    }

    //dp means the number of arithmetic sequences ended up with nums[i]
    int numberofArithmeticSlices_S2(std::vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {return 0;}
        std::vector<int> dp(n, 0);
        for (int i = 2; i < n; ++i) {
            if (nums[i - 1] - nums[i - 2] == nums[i] - nums[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            }
        }
        return std::accumulate(dp.begin(), dp.end(), 0);
    }

    int numberofArithmeticSlices_withCompression(std::vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {return 0;}
        int subLength = 2;
        int res = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (nums[i] - nums[i - 1] == nums[i + 1] - nums[i]) {
                ++subLength;
            } else {
                res += (subLength - 1) * (subLength -  2) / 2;
                subLength = 2;
            }
        }
        res += (subLength - 1) * (subLength -  2) / 2;
        return res;
    }
};