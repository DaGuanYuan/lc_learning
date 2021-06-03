#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<double> findAllProbability(int n) {
        std::vector<double> res{};
        if (n < 1) {return res;}
        // dp[0] is not used
        std::vector<double> dp(6 * n + 1, 0);
        // initialize n = 1
        for (int x = 1; x <= 6; x++) {dp[x] = 1.0/6.0;}
        for (int i = 2; i <= n; i++) {
            for (int j = 6 * i; j >= i; j--) {
                // dp[j] = (sigma dp[j - k]) / 6.0, k range from 1 to 6
                // !!!!!!NOT dp[j] += (sigma dp[j - k]) / 6.0!!!!!!!
                // so dp[j] should be assigned to 0
                dp[j] = 0;
                for (int k = 1; k <= 6; k++) {
                    // i - 1 means the (i)th dice can only be obtained by (i-1)th dice
                    if (j - k >= i - 1) {dp[j] += (dp[j - k] / 6.0);}
                }
            }
        }
        res.assign(dp.begin() + n, dp.end());
        return res;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    // n < 1;
    // n = 1, 2, 3
    // n = 10
    int n = 3;
    std::vector<double> res = s.findAllProbability(n);
    if (res.empty()) {printf("Please check your input!\n");}
    else {
        printf("All probability n dices can exhibit is showed below:\n[ ");
        for (std::vector<double>::iterator it = res.begin(); it != res.end(); it++) {
            printf("%f ", *it);
        }
        printf("]\n");
    }
    return 0;
}