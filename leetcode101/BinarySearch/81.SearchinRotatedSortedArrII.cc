#include <iostream>
#include <vector>

class Solution {
public:
    bool searchinRotatedArr(std::vector<int>& nums, int target) {
        if (nums.empty()) {return false;}
        int left = 0, right = nums.size() - 1, mid = 0;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (nums[mid] == target ||
                nums[left] == target ||
                nums[right] == target) {return true;}
            if (nums[mid] > target && nums[left] <= target) {right = mid - 1;}
            else if (nums[mid] < target && nums[left] <= target) {left++;}
            else if (nums[mid] < target && nums[right] >= target) {left = mid + 1;}
            else if (nums[mid] > target && nums[right] >= target) {right--;}
            else {return false;}
        }
        return false;
    }

    // Dividing based on the position of nums[mid] might be more efficient
    bool searchinRotatedArr_Solution2(std::vector<int>& nums, int target) {
        if (nums.empty()) {return false;}
        int left = 0, right = nums.size() - 1, mid = 0;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (nums[mid] == target) {return true;}
            if (nums[mid] == nums[left]) {++left;}
            else if (nums[mid] > nums[left]) {
                if (target >= nums[left] && nums[mid] > target) {right = mid - 1;}
                else {left = mid + 1;}
            } else {
                if (target <= nums[right] && nums[mid] < target) {left = mid + 1;}
                else {right = mid - 1;}
            }
        }
        return false;
    }
};