#include <iostream>
#include <vector>

class Solution {
    void sortColors(std::vector<int>& nums) {
        if (nums.empty()) {return;}
        int left = 0, right = 1;
        while (right < nums.size()) {
            while (nums[left] == 0 && right < nums.size()) {
                ++left;
                ++right;
            }
            if (right < nums.size() && nums[right] == 0) {
                std::swap(nums[left], nums[right]);
                ++left;    
            }
            ++right;
        }
        right = left + 1;
        while (right < nums.size()) {
            while (nums[left] == 1 && right < nums.size()) {
                ++left;
                ++right;
            }
            if (right < nums.size() && nums[right] == 1) {
                std::swap(nums[left], nums[right]);
                ++left;
            }
            ++right;
        }
    }

    // still two points. Notice whatever the loop does, ++right
    // so for loop is prefered! Also, right start from left will
    // be more concise 
    void sortColors_optimizationCoding(std::vector<int>& nums) {
        if (nums.empty()) {return;}
        int left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) {
                std::swap(nums[left], nums[right]);
                ++left;
            }
        }
        for (int right = left; right < nums.size(); ++right) {
            if (nums[right] == 1) {
                std::swap(nums[left], nums[right]);
                ++left;
            }
        }
    }

    // three points, one traversal
    void sortColors_Solution2(std::vector<int>& nums) {
        if (nums.empty()) {return;}
        int ptr = 0, left = 0, right = nums.size() - 1;
        while (ptr <= right) {
            if (nums[ptr] == 2) {std::swap(nums[ptr], nums[right--]);}
            if (nums[ptr] == 0) {std::swap(nums[ptr], nums[left++]);}
            ++ptr;
        }
    }

    void sortColors_Solution3(std::vector<int>& nums) {
        if (nums.empty()) {return;}
        int p0 = 0, p1 = 0;
        for (int ptr = 0; ptr < nums.size(); ++ptr) {
            if (nums[ptr] == 1) {
                std::swap(nums[ptr], nums[p1]);
                ++p1;    
            } else if (nums[ptr] == 0) {
                std::swap(nums[ptr], nums[p0]);
                if (p0 < p1) {std::swap(nums[ptr], nums[p1]);}
                ++p0;
                ++p1;
            }
        }
    }
};