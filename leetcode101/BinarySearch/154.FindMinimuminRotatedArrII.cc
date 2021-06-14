#include <iostream>
#include <vector>

class Solution {
public:
    int findMinimumNuminRotatedArray(std::vector<int>& nums) {
        if (nums.empty()) {return -1;}
        int left = 0, right = nums.size() - 1, mid = 0;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (nums[mid] == nums[left]) {++left;}
            else if (nums[mid] > nums[left]) {left = mid + 1;}
            else {right = mid - 1;}
        }
        return nums[mid];
    }
};
