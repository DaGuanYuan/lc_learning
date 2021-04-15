#include <iostream>
#include <vector>

class Solution {
public:
    int maxProductAfterCutting_solution1(int length) {
        if (length <= 1) {return 0;}
        if (length == 2) {return 1;}
        if (length == 3) {return 2;}
        std::vector<int> dp(length + 1, 1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        int product = 0;
        for (int i = 4; i <= length; i++) {
            product = 0;
            for (int j = 1; j <= i / 2; j++) {
                product = dp[j] * dp[i - j];
                dp[i] = product > dp[i] ? product : dp[i];
            }
        }
        return dp[length];
    }

    int maxProductAfterCutting_solution2(int length) {
        if (length <= 1) {return 0;}
        if (length == 2) {return 1;}
        if (length == 3) {return 2;}
        if (length == 4) {return 4;}
        int ans = 1;
        while (length >= 5) {
            ans *= 3;
            length -= 3;
        }
        ans *= length;
        return ans;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    int length = 10;
    printf("%d\n", s.maxProductAfterCutting_solution1(length));
    return 0;
}