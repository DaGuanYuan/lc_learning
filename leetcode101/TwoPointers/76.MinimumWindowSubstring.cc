#include <iostream>
#include <string.h>
#include <unordered_map>

class Solution {
public:
    std::string minWindow(std::string& s, std::string& t) {
        if (s.empty() || t.empty()) {return "";}
        std::unordered_map<char, bool> hashMap_exist;
        std::unordered_map<char, int> hashMap_cnt;
        for (const char ch : t) {
            hashMap_exist[ch] = true;
            ++hashMap_cnt[ch];
        }
        int right = 0, left = 0, cnt = 0, min_left = 0, min_size = s.size() + 1;
        while (right < s.size()) {
            if (hashMap_exist[s[right]]) {
                if (--hashMap_cnt[s[right]] >= 0) {++cnt;}
                while (cnt == t.size()) {
                    if (right - left + 1 < min_size) {
                        min_left = left;
                        min_size = right - left + 1;
                    }
                    if (hashMap_exist[s[left]] && ++hashMap_cnt[s[left]] > 0) {--cnt;}
                    ++left;
                }
            }
            ++right;
        }
        return min_size < s.size() + 1 ? s.substr(min_left, min_size) : "";
    }
};

// happy birthday!!!!