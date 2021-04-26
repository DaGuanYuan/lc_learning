#include <iostream>
#include <string.h>
#include <vector>

class Solution {
public:
    bool matchRegExp(std::string str, std::string pattern) {
        int strSize = str.size();
        int patternSize = pattern.size();
        std::vector<std::vector<bool> > dp(strSize + 1, std::vector<bool>(patternSize + 1, false));
        dp[0][0] = true;
        for (int j = 2; j <= patternSize; j += 2) {
            dp[0][j] = dp[0][j - 2] && pattern[j - 1] == '*';
        }
        if (strSize > 0 && (pattern[0] == str[0] || pattern[0] == '.')) {dp[1][1] = true;}
        for (int i = 1; i <= strSize; i++) {
            for (int j = 2; j <= patternSize; j++) {
                if (pattern[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2]
                    || dp[i][j - 1]
                    || (dp[i - 1][j - 1] && str[i - 1] == pattern[j - 2])
                    || (pattern[j - 2] == '.' && dp[i - 1][j]);
                }
                else {
                    dp[i][j] = dp[i - 1][j - 1] && (pattern[j - 1] == str[i - 1] || pattern[j - 1] == '.');
                }
            }
        }
        return dp[strSize][patternSize];
    } 
};

int main(int argc, const char** argv) {
    // pattern[j - 1] == '*' -> pattern[j - 2] == '.' && dp[i - 1][j]
    std::string str1 = "aaa";
    std::string pattern1 = ".*";
    // pattern[j - 1] == '*' -> dp[i][j - 2]
    std::string str2 = "a";
    std::string pattern2 = "ab*";
    // pattern[j - 1] == '*' -> dp[i][j - 1]
    std::string str3 = "abb";
    std::string pattern3 = "abb*";
    // pattern[j - 1] == '*' -> dp[i - 1][j - 1] && str[i - 1] == pattern[j - 2]
    std::string str4 = "abb";
    std::string pattern4 = "ab*";
    // pattern[j - 1] != '*' -> dp[i - 1][j - 1] && str[i - 1] == pattern[j - 1]
    std::string str5 = "abb";
    std::string pattern5 = "abb";
    // pattern[j - 1] != '*' -> dp[i - 1][j - 1] && pattern[j - 1] == '.'
    std::string str6 = "abb";
    std::string pattern6 = "ab.";

    Solution s;
    if (s.matchRegExp(str5, pattern5)) {printf("Matched!\n");}
    else {printf("Failed to Match\n");}
    return 0;
}