#include <iostream>
#include <vector>

class Solution {
public:
    int singleNonDuplicated(std::vector<int>& nums) {
        if (nums.size() % 2 == 0) {return INT32_MAX;}
        int left = 0, mid = 0, leftHalf = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (mid + 1 >= nums.size() ||
                mid - 1 < 0 ||
                (nums[mid] != nums[mid + 1] &&
                nums[mid] != nums[mid - 1])) {return nums[mid];}
            else if (nums[mid] == nums[mid + 1]) {
                leftHalf = mid - left;
                if (leftHalf % 2 == 1) {right = mid - 1;}
                else {left = mid + 2;}
            }
            else if (nums[mid] == nums[mid - 1]) {
                leftHalf = mid - 1 - left;
                if (leftHalf % 2 == 1) {right = mid - 2;}
                else {left = mid + 1;}
            }
        }
        return INT32_MIN;
    }
};
