#include <iostream>
#include <string.h>
#include <unordered_map>

class Solution {
public:
    std::string minWindow(std::string& s, std::string& t) {
        if (s.empty() || t.empty()) {return "";}
        std::unordered_map<char, int> hashMap_t;
        std::unordered_map<char, int> hashMap_s;
        for (const char ch : t) {++hashMap_t[ch];}
        
    }
};

// happy birthday!!!!