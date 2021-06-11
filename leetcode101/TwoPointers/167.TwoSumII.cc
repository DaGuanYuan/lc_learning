#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& arr, int target) {
        if (arr.empty()) {return {};}
        int left = 0;
        int right = arr.size() - 1;
        int sum = 0;
        while (left < right) {
            sum = arr[left] + arr[right];
            if (sum == target) {return {left, right};}
            else if (sum > target) {right--;}
            else {left++;}
        }
        return {};
    }
};