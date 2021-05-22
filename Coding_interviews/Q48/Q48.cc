#include <iostream>
#include <string.h>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int longestSubstringWithoutDuplication(const std::string& str) {
        if (str.empty()) {return 0;}
        std::unordered_map<char, int> mp;
        int left = 0;
        int right = 0;
        int length = 0;
        while (right < str.size()) {
            mp[str[left]] = left;
            right = left + 1;
            while (right < str.size() && mp.find(str[right]) == mp.end()) {
                mp[str[right]] = right;
                right++;    
            }
            length = std::max(length, static_cast<int>(mp.size()));
            left = mp[str[right]] + 1;
            mp.clear();
        }
        return length;
    }

    int longestSubstringWithoutDuplication_dp(const std::string& str) {
        if (str.empty()) {return 0;}
        std::unordered_map<char, int> mp;
        int n = str.size();
        // std::vector<int> dp (n + 1, 0);
        // !when dp[i] is only related dp[i-1], dp[i-2] ... , dp[i - k]
        // consider using k variables to substitute dp vector
        int dp = 0; //consider dp[i] is only related to dp[i - 1]
        int dupIndex = 0;
        int maxLen = 0;
        for (int i = 1; i <= n; i++) {
            if (mp.find(str[i - 1]) != mp.end()) {
                dupIndex = std::max(dupIndex, mp[str[i - 1]]);
                dp = i - 1 - dupIndex;
            }
            else {dp = dp + 1;}
            mp[str[i - 1]] = i - 1;
            maxLen = std::max(maxLen, dp);
        }
        return maxLen;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    // empty, only 1 character
    // have repeated characters || all characters are unique
    // all characters are same
    std::string str {"pwwkew"};
    int res = s.longestSubstringWithoutDuplication(str);
    printf("The longest size of substring without duplication of str is %d\n", res);
    return 0;
}