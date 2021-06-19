#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= 0 || k > n) {return {};}
        std::vector<int> res;
        std::unordered_map<int, int> hashMap;
        for (const int& val : nums) {++hashMap[val];}
    }
};
