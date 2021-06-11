#include <iostream>
#include <string.h>
#include <vector>

class Solution {
public:
    bool isSubStr(std::string& s, std::string& subStr) {
        if (subStr.size() > s.size()) {return false;}
        int pS = 0;
        int pSubStr = 0;
        while (pSubStr < subStr.size() && pS < s.size()) {
            if (s[pS] == subStr[pSubStr]) {++pS; ++pSubStr;}
            else {++pS;}
        }
        return pSubStr == subStr.size();
    }

    std::string findLongestWord(std::string& s,
                                std::vector<std::string>& dictionary) {
        if (s.empty() || dictionary.empty()) {return "";}
        int length = 0;
        std::string res;
        for (std::string& str : dictionary) {
            if (isSubStr(s, str)) {
                if (str.size() > length) {
                    length = str.size();
                    res = str;
                } else if (str.size() == length) {
                    res = res < str ? res : str;
                }
            }
        }
        return res;
    }
}; 

// happy birthday!!!!