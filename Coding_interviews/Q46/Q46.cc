#include <iostream>
#include <vector>
#include <string.h>

class Solution {
public:
    int getTranslationCount_dpFrom0(int num) {
        if (num < 0) {return 0;}
        if (num < 10) {return 1;}   //ensure dp[1] is existing
        std::string num2String = std::to_string(num);
        int n = num2String.size();
        std::vector<int> dp(n, 0);
        dp[0] = 1;  //starting from 0
        dp[1] = 1;
        if (checkVal(num2String, 1)) {dp[1] = 2;}
        for (int i = 2; i < n; i++) {
            dp[i] = dp[i - 1];
            if (checkVal(num2String, i)) {dp[i] += dp[i - 2];}
        }
        return dp[n - 1];
    }

    // As you can see, vector starting from 0 is somewhat annoying since a lot of
    // boundaries should be considered carefully. Here, dp starting from 1 is highly
    // recommended, meaning dp[0] represents the null or no-sense
    int getTranslationCount_dpFrom1(int num) {
            if (num < 0) {return 0;}
            std::string num2String = std::to_string(num);
            int n = num2String.size();
            std::vector<int> dp(n + 1, 0);
            // index 0 means have no character,
            // dp[0] could be derived from dp[2] - dp[1] if checkVal() is true;
            // or dp[1] if checkVal() is false. both equal to 1;
            dp[0] = 1;
            dp[1] = 1;  //starting from 1
            for (int i = 2; i <= n; i++) {
                dp[i] = dp[i - 1];
                if (checkVal(num2String, i - 1)) {dp[i] += dp[i - 2];}
            }
            return dp[n];
    }

    // Consider that dp[i] is only related to dp[i - 1] and dp[i - 2]
    // so we can use two variable a, b to substitute dp vector
    // Also, we can use num/10 and num%10 to get digit nums
    int getTranslationCount_optimization(int num) {
        if (num < 0) {return 0;}
        int a = 1; // dp[0], representing nothing firstly
        int b = 1; // dp[1], starting from the end
        int c = 1; // dp[current], initial as 1
        int x = 0; // ten
        int y = num % 10; // unit
        num /= 10;
        // from right to left
        while (num) {
            x = num % 10;
            num /= 10;
            c = x != 0 && 10 * x + y <= 25 ? a + b : b;
            a = b;
            b = c;
            y = x;
        }
        return c;
    }

    bool checkVal(const std::string& str, int pos) {
            // Please Notice: '0' != 0
            // 3 = '3' - '0'
            // 3 != '3'
            return str[pos - 1] != '0' 
                && (str[pos] - '0' + 10 * (str[pos - 1] - '0') <= 25);
        }
};

int main(int argc, const char** argv) {
    Solution s;
    // boundary test: num < 0; num = 0; num = 1
    // only one way to translate n = 9999999
    // n includes "25" "26" "01" "10"
    int res = s.getTranslationCount_optimization(12259);
    printf("The number has %d way(s) to translate to string\n", res);
    return 0;
}