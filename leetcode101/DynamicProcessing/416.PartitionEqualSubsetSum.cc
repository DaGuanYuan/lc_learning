#include <iostream>
#include <vector>

class Solution {
public:
    bool canPartition(std::vector<int>& nums) {
        int N = nums.size();
        int sum = 0;
        for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
            sum += *it;
        }
        if ((sum & 0x1) == 1 || N <= 1) {return false;}
        int target = (sum >> 1);
        std::vector<std::vector<bool> > dp(N + 1, std::vector<bool>(target + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= N; ++i) {
            int val = nums[i - 1];
            for (int j = 1; j <= target; ++j) {
                if (j >= val) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - val];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[N][target];
    }

    bool canPartition(std::vector<int>& nums) {
        int N = nums.size();
        int sum = 0;
        for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
            sum += *it;
        }
        if ((sum & 0x01) == 1 || N <= 1) {return false;}
        int target = (sum >> 1);
        std::vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int i = 1; i <= N; ++i) {
            int val = nums[i - 1];
            for (int j = target; j >= val; --j) {
                dp[j] = dp[j] || dp[j -val];
            }
        }
        return dp[target];
    }
};