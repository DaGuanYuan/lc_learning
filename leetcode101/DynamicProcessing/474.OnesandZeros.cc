#include <iostream>
#include <vector>
#include <string.h>

class Solution {
public:
    std::pair<int, int> countZerosandOnes(const std::string& strs) {
        std::pair<int, int> count{0, 0};
        for (const char ch : strs) {
            if (ch == '0') {++count.first;}
            if (ch == '1') {++count.second;}
        }
        return count;
    }

    int findMaxForm(std::vector<std::string> strs, int m, int n) {
        int sizeStr = strs.size();
        if (sizeStr == 0 || (m <= 0 && n <= 0)) {return 0;}
        std::vector<std::vector<int> > dp(m + 1, std::vector<int>(n + 1, 0));
        for (int i = 0; i < sizeStr; ++i) {
            std::pair<int, int> countNums = countZerosandOnes(strs[i]);
            int m_nums = countNums.first;
            int n_nums = countNums.second;
            for (int j = m; j >= m_nums; --j) {
                for (int k = n; k >= n_nums; --k) {
                    dp[j][k] = std::max(dp[j][k], dp[j - m_nums][k - n_nums] + 1);
                }
            }
        }
        return dp[m][n];
    }
};