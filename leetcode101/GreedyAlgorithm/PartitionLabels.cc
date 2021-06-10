#include <iostream>
#include <vector>
#include <string.h>

class Solution {
public:
    std::vector<int> partitionLabels(std::string& s) {
        if (s.empty()) {return {};}
        int hashMap[32];
        for (int i = 0; i < s.size(); i++) {hashMap[s[i] - 'a'] = i;}
        int left = 0;
        int right = hashMap[s[left] - 'a'];
        int begin = left;
        std::vector<int> partSizes;
        while (left < s.size()) {
            right = std::max(right, hashMap[s[left] - 'a']);
            if (left == right) {
                partSizes.push_back(right - begin + 1);
                begin = left + 1;
            }
            left++;
        }
        return partSizes;
    }
};