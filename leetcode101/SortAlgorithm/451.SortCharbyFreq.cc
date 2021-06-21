#include <iostream>
#include <string.h>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::string frequencySort(std::string& s) {
        if (s.empty()) {return "";}
        std::unordered_map<char, int> hashMap;
        std::string res;
        for (const char c : s) {++hashMap[c];}
        int minASCII = INT32_MAX, maxASCII = INT32_MIN;
        for (const std::pair<char, int>& p: hashMap) {
            maxASCII = maxASCII > p.second ? maxASCII : p.second;
            minASCII = minASCII < p.second ? minASCII : p.second;
        }
        int bucketSize = maxASCII - minASCII + 1;
        std::vector<std::string> bucket(bucketSize, std::string{});
        for (const std::pair<char, int>& p : hashMap) {
            bucket[p.second - minASCII].push_back(p.first);
        }
        for (int i = bucketSize - 1; i >= 0; --i) {
            if (!bucket[i].empty()) {
                for (const char ch : bucket[i]) {
                    int times = i + minASCII;
                    while (times) {
                        res.push_back(ch);
                        --times;
                    }
                }
            }
        }
        return res;
    }
};