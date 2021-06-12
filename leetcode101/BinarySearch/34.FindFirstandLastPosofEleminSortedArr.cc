#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        if (nums.empty()) {return {-1, -1};}
        int left = 0, right = nums.size() - 1, mid = 0;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (nums[mid] >= target) {right = mid - 1;}
            else {left = mid + 1;}
        }
        int leftIndex = left;
        left = 0, right = nums.size() - 1;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (nums[mid] <= target) {left = mid + 1;}
            else {right = mid - 1;}
        }
        int rightIndex = right;
        if (leftIndex >= nums.size() ||
            rightIndex < 0 || 
            nums[leftIndex] != target) {return {-1, -1};}
        return {leftIndex, rightIndex};
    }
};