#include <iostream>
#include <string.h>
#include <unordered_map>

class Solution {
public:
    char firstNotRepeatingChar(std::string& str) {
        if (str.empty()) {return ' ';}
        std::unordered_map<char, int> mp;
        for (int i = 0; i < str.size(); i++) {mp[str[i]]++;}
        for (int i = 0; i < str.size(); i++) {
            if (mp[str[i]] == 1) {return str[i];}
        }
        return ' ';
    }
};

int main(int argc, const char** argv) {
    Solution s;
    // empty, only one character
    // has no repeated characters
    // has repeated characters
    // all characters are the same
    std::string str {"abaccdeff"};
    char firstNotRptChar = s.firstNotRepeatingChar(str);
    printf("The first character which is not repeating is %c\n", firstNotRptChar);
    return 0;
}