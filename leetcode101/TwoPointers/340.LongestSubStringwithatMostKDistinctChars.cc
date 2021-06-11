#include <iostream>
#include <string.h>
#include <unordered_map>

class Solution {
public:
    int lengthofLongestSubstrwithKDistinctChar(std::string& s, int k) {
        int strSize = s.size();
        if (k < 0) {return -1;}
        if (k >= strSize) {return strSize;}
        std::unordered_map<char, int> hashMap;
        int left = 0, right = 0, maxLen = 0;
        while (right < strSize) {
            ++hashMap[s[right]];
            while (hashMap.size() > k) {
                --hashMap[s[left]];
                if (hashMap[s[left]] == 0) {hashMap.erase(s[left]);}
                ++left;
            }
            maxLen = std::max(maxLen, right - left + 1);
            ++right;
        }
        return maxLen;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    std::string str{"eceba"};
    int k = 2;
    int maxLen = s.lengthofLongestSubstrwithKDistinctChar(str, k);
    printf("The length of the longest substring with %d distinct characters is %d\n", k, maxLen);
    return 0;
}

// happy birthday!!!!