#include <iostream>
#include <vector>

class Solution {
public:
    int findMinimumNuminRotatedArray(std::vector<int>& nums) {
        if (nums.empty()) {return -1;}
        int left = 0, right = nums.size() - 1, mid = 0;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            // here must be right since 3 / 2 = 1 (Rounding left)
            if (nums[mid] == nums[right]) {--right;}
            else if (nums[mid] > nums[right]) {left = mid + 1;}
            // modified right = mid - 1 -> right = mid to ensure minimum number not being passed
            else {right = mid;}
        }
        return nums[mid];
    }
};
