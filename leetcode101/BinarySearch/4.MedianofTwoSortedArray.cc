#include <iostream>
#include <vector>

class Solution {
    double findTopKofTwoSortedArr(std::vector<int>& nums1,
                                  std::vector<int>& nums2,
                                  int m,
                                  int n,
                                  int k) {
        int index1 = 0, index2 = 0;
        while (true) {
            if (index1 == m) {return nums2[index2 + k - 1];}
            if (index2 == n) {return nums1[index1 + k - 1];}
            if (k == 1) {return std::min(nums1[index1], nums2[index2]);}
            int pivotIndex1 = std::min(index1 + k / 2 - 1, m - 1);
            int pivotIndex2 = std::min(index2 + k / 2 - 1, n - 1);
            int pivot1 = nums1[pivotIndex1];
            int pivot2 = nums2[pivotIndex2];
            if (pivot1 <= pivot2) {
                k -= (pivotIndex1 - index1 + 1);
                index1 = pivotIndex1 + 1;
            } else {
                k -= (pivotIndex2 - index2 + 1);
                index2 = pivotIndex2 + 1;
            }
        }
        return 0;
    }

    double findMedianofSortedArrays(std::vector<int>& nums1,
                                    std::vector<int>& nums2) {
        if (nums1.empty() && nums2.empty()) {return 0;}
        int m = nums1.size();
        int n = nums2.size();
        int medianPos = (m + n) >> 1;
        double res = findTopKofTwoSortedArr(nums1, nums2, m, n, medianPos + 1);
        if (((m + n) & 0x1) == 0) {res = (res + findTopKofTwoSortedArr(nums1, nums2, m, n, medianPos)) / 2.0;}
        return res;
    }
};