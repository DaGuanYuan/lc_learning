#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    void combinationSum2(std::vector<std::vector<int> >& res,
                         std::vector<int>& temp,
                         std::vector<std::pair<int, int>>& freq,
                         std::vector<int>& candidates,
                         int target,
                         int pos) {
        if (target == 0) {
            res.push_back(temp);
            return;
        }
        if (target < 0 || pos == freq.size()) {return;}
        int maxTime = std::min(freq[pos].second, target / freq[pos].first);
        for (int i = 1; i <= maxTime; ++i) {
            temp.push_back(freq[pos].first);
            combinationSum2(res, temp, freq, candidates, target - i * freq[pos].first, pos + 1);
        }
        for (int i = 1; i <= maxTime; ++i) {temp.pop_back();}
        combinationSum2(res, temp, freq, candidates, target, pos+1);
    }

    std::vector<std::vector<int> > combinationSum2(std::vector<int>& candidates, int target) {
        if (candidates.empty()) {return {};}
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int> > res{};
        std::vector<int> temp{};
        std::vector<std::pair<int, int> > freq;
        for (const int& val : candidates) {
            if (freq.empty() || freq.back().first != val) {
                freq.emplace_back(val, 1);
            } else {
                ++freq.back().second;
            }
        }
        combinationSum2(res, temp, freq, candidates, target, 0);
        return res;
    }
};