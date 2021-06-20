#include <iostream>
#include <vector>

class Solution {
public:
    void mySwap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    int Partition(std::vector<int>& nums, int left, int right) {
        int begin = left;
        int pivotVal = nums[begin];
        while (left < right) {
            while (left < right && nums[right] < pivotVal) {--right;}
            while (left < right && nums[left] >= pivotVal) {++left;}
            if (left < right) {mySwap(nums[left], nums[right]);}
        }
        mySwap(nums[begin], nums[left]);
        return left;
    }

    int findKthLargest(std::vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= 0 || k <= 0 || k > n) {return INT32_MIN;}
        int left = 0, right = n - 1, pivotIndex = 0;
        while (left <= right) {
            pivotIndex = Partition(nums, left, right);
            if (pivotIndex == k - 1) {return nums[pivotIndex];}
            else if (pivotIndex > k - 1) {right = pivotIndex - 1;}
            else {left = pivotIndex + 1;}
        }
        return 0;
    }
};