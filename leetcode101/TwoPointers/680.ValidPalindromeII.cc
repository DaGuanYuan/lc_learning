#include <iostream>
#include <string.h>

class Solution {
public:
    bool validPalindrome(std::string& s) {
        if (s.empty()) {return false;}
        int left = 0;
        int right = s.size() - 1;
        int eraseNum1 = 0;
        while (left <= right) {
            if (eraseNum1 > 1) {break;}
            if (s[left] == s[right]) {++left; --right;}
            else {++eraseNum1; ++left;}
        }
        left = 0, right = s.size() - 1;
        int eraseNum2 = 0;
        while (left <= right) {
            if (eraseNum2 > 1) {break;}
            if (s[left] == s[right]) {++left; --right;}
            else {++eraseNum2; --right;}
        }
        return eraseNum1 <= 1 || eraseNum2 <= 1;
    }
};

// happy birthday!!!!