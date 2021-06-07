#include <iostream>
#include <string.h>

class Solution {
public:
    int str2Int(std::string str) {
        if (str.empty()) {
            gStatus = 0;
            return 0;
        }
        long long res = 0;
        bool isNegative = 0;
        int start = 0;
        while (start < str.size() && str[start] == ' ') {start++;}
        for (int i = start; i < str.size(); i++) {
            if (i == start && str[i] == '+') {continue;}
            else if (i == start && str[i] == '-') {
                isNegative = 1;
                continue;
            }
            else if (str[i] > '9' || str[i] < '0') {break;}
            else {res = res * 10 + str[i] - '0';}

            if (res >= INT32_MAX && !isNegative) {return INT32_MAX;}
            else if (-res <= INT32_MIN && isNegative) {return INT32_MIN;}   
        }
        return isNegative ? -res : res;
    }

    int gStatus = 1;
};

int main(int argc, const char** argv) {
    Solution s;
    // str.empty()
    // str contains '+','-' in the beginning of the string
    // str contains ' ' in the beginning
    // str contains characters out of '0'~'9'
    // atoi(str) = 0x7FFFFFFF
    // atoi(str) = 0x80000000
    // atoi(str) > 0x7FFFFFFF || < 0x80000000
    // normal test(positive num, 0, negative num)
    std::string str {"2147483648"};
    int res = s.str2Int(str);
    printf("The intege represented in str is: %d\n", res);
    return 0;
}