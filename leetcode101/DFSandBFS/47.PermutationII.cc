#include <iostream>
#include <vector>
#include <set>

class Solution {
public:
    void permuteUnique(std::vector<int>& nums, 
                       std::vector<std::vector<int> >& res,
                       std::vector<int>& temp,
                       int k) {
        if (k == nums.size()) {
            res.push_back(temp);
            return;
        }
        std::set<int> st;
        for (int i = k; i < nums.size(); ++i) {
            if (st.find(nums[i]) != st.end()) {continue;}
            st.emplace(nums[i]);
            std::swap(nums[i], nums[k]);
            temp.push_back(nums[k]);
            permuteUnique(nums, res, temp, k + 1);
            temp.pop_back();
            std::swap(nums[i], nums[k]);
        }
    }

    std::vector<std::vector<int> > permuteUnique(std::vector<int>& nums) {
        if (nums.empty()) {return {};}
        std::vector<std::vector<int> > res;
        std::vector<int> temp;
        permuteUnique(nums, res, temp, 0);
        return res;
    }
};