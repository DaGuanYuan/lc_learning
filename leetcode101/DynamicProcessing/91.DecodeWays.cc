#include <iostream>
#include <vector>
#include <string.h>

class Solution {
public:
    int numDecodings(std::string& s) {
        if (s.empty() || s[0] == '0') {return 0;}
        int n = s.size();
        std::vector<int> dp(n + 1, 1);
        dp[0] = dp[1] = 1;
        int prev = s[0] - '0';
        for (int i = 2; i <= n; ++i) {
            int cur = s[i - 1] - '0';
            if (cur && prev) {
                if (cur + 10 * prev <= 26) {
                    dp[i] = dp[i - 1] + dp[i - 2];
                } else {
                    dp[i] = dp[i - 1];
                }
            } else if (!cur) {
                if (prev == 0 || prev > 2) {return 0;}
                else {dp[i] = dp[i - 2];}
            } else {
                dp[i] = dp[i - 1];
            }
            prev = cur;
        }
        return dp[n];
    }

        int numDecodings_withCompression(std::string& s) {
        if (s.empty() || s[0] == '0') {return 0;}
        int n = s.size();
        int a = 1, b = 1, c = 1;
        int prev = s[0] - '0';
        for (int i = 2; i <= n; ++i) {
            int cur = s[i - 1] - '0';
            if (cur && prev) {
                if (cur + 10 * prev <= 26) {
                    c = a + b;
                } else {
                    c = b;
                }
            } else if (!cur) {
                if (prev == 0 || prev > 2) {return 0;}
                else {c = a;}
            } else {
                c = b;
            }
            prev = cur;
            a = b;
            b = c;
        }
        return c;
    }
};
