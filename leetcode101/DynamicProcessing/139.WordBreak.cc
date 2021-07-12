#include <iostream>
#include <unordered_set>
#include <vector>
#include <string.h>

class Solution {
public:
    bool wordBreak(std::string& s, std::vector<std::string>& wordDict) {
        if (s.empty() || wordDict.empty()) {return false;}
        int n = s.size();
        std::vector<bool> dp(n + 1, false);
        std::unordered_set<std::string> dict(wordDict.begin(), wordDict.end());
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int k = 1; k <= i; ++k) {
                dp[i] = dp[i] || (dp[i - k] && dict.count(std::string(s.begin() + i - k, s.begin() + i)));
            }
        }
        return dp[n];
    }

    bool wordBreak_S2(std::string& s, std::vector<std::string>& wordDict) {
        if (s.empty() || wordDict.empty()) {return false;}
        int n = s.size();
        std::vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (const std::string& word : wordDict) {
                int len = word.size();
                if (i >= len && s.substr(i - len, len) == word) {
                    dp[i] = dp[i] || dp[i - len];
                }
            }
        }
        return dp[n];
    }
};
