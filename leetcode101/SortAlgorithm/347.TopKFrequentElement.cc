#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= 0 || k > n) {return {};}
        std::vector<int> res;
        std::unordered_map<int, int> hashMap;
        for (const int& val : nums) {++hashMap[val];}
        auto compare = [] (std::pair<int, int>& p1, 
                           std::pair<int, int>& p2) -> bool {
            return p1.second > p2.second;
        };
        std::priority_queue<std::pair<int, int>, 
                            std::vector<std::pair<int, int> >,
                            decltype(compare)> minHeap(compare);
        for (const std::pair<int, int>& p : hashMap) {
            if (minHeap.size() == k) {
                if (p.second > minHeap.top().second) {
                    minHeap.push(p);
                    minHeap.pop();
                }
            } else {minHeap.push(p);}
        }
        while (!minHeap.empty()) {
            res.push_back(minHeap.top().first);
            minHeap.pop();
        }
        return res;
    }

    std::vector<int> topKfrequent_Solution2(std::vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= 0 || k > n) {return {};}
        std::vector<int> res;
        std::unordered_map<int, int> hashMap;
        for (const int& val : nums) {++hashMap[val];}
        int maxVal = INT32_MIN, minVal = INT32_MAX;
        for (const std::pair<int, int>& p : hashMap) {
            maxVal = maxVal > p.second ? maxVal : p.second;
            minVal = minVal < p.second ? minVal : p.second;
        }
        int bucketSize = maxVal - minVal + 1;
        std::vector<std::vector<int> > bucket(bucketSize, std::vector<int> {});
        for (const std::pair<int, int>& p : hashMap) {
            bucket[p.second - minVal].push_back(p.first);
        }
        while (k && bucketSize >= 1) {
            if (!bucket[bucketSize - 1].empty()) {
                for (const int& val : bucket[bucketSize - 1]) {
                    res.push_back(val);
                    --k;
                    if (k == 0) {break;}
                }
            }
            --bucketSize;
        }
        return res;
    }
};
