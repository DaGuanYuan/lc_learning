#include <iostream>
#include <vector>

class Solution {
public:
    void permuteCore(std::vector<int>& nums, int k) {
        if (k >= nums.size() - 1) {
            res.push_back(nums);
            return;
        }
        for (int i = k; i < nums.size(); ++i) {
            std::swap(nums[i], nums[k]);
            permuteCore(nums, k + 1);
            std::swap(nums[i], nums[k]);
        }
    }

    std::vector<std::vector<int> > permute(std::vector<int>& nums) {
        if (nums.empty()) {return {};}
        permuteCore(nums, 0);
        return res;
    }
private:
    std::vector<std::vector<int> > res;
};