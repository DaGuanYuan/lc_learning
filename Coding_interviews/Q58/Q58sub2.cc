#include <iostream>
#include <string.h>

class Solution {
public:
    void reverseString(std::string& str, int start, int end) {
        char temp = '\0';
        while (start <= end) {
            temp = str[start];
            str[start] = str[end];
            str[end] = temp;
            start++;
            end--;
        }
    }

    std::string leftRotateStringbyK(std::string& str, int k) {
        int n = str.size();
        if (n <= 1 || k <= 0) {return str;}
        k = k % n;  //for k > n
        int firstBegin = 0;
        int firstEnd = k - 1;
        int secondBegin = k;
        int secondEnd = str.size() - 1;
        reverseString(str, firstBegin, firstEnd);
        reverseString(str, secondBegin, secondEnd);
        reverseString(str, firstBegin, secondEnd);
        return str;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    // str.size() <= 1
    // str has repeated characters / all characters are unique
    // k <= 0;
    // k = 1, str.size() - 1;
    // k >= str.size()
    // normal test
    std::string str {"abcdefg"};
    int k = 2;
    std::string res = s.leftRotateStringbyK(str, k);
    if (res.empty()) {printf("Please check your input!\n");}
    else {
        printf("String after rotating toward left by k is showed below:\n");
        printf("%s\n", res.c_str());
    }
    return 0;
}