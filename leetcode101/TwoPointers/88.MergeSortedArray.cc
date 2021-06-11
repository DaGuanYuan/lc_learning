#include <iostream>
#include <vector>

class Solution {
public:
    // Here, we assume nums1.size() = m + n and we settle the 
    // sorted result into nums1 as a result
    void mergeTwoSoredArr(std::vector<int>& nums1, int m
                        , std::vector<int>& nums2, int n) {
        if (m == 0) {
            nums1 = nums2;
            return;    
        }
        if (n == 0) {return;}
        int p1 = m - 1;
        int p2 = n - 1;
        int pSorted = m + n - 1;
        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] >= nums2[p2]) {nums1[pSorted--] = nums1[p1--];}
            else {nums1[pSorted--] = nums2[p2--];}
        }
        while (p2 >= 0) {nums1[pSorted--] = nums2[p2--];}
    }
};