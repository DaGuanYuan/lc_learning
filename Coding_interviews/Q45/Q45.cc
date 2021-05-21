#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

class Solution {
public:
    std::string minNumber(std::vector<int>& nums) {
        std::string res {};
        if (nums.empty()) {return res;}
        std::vector<std::string> nums2String;
        for (const int& val : nums) {nums2String.push_back(std::to_string(val));}
        quickSort(nums2String, 0, nums2String.size() - 1);
        for (const std::string& str : nums2String) {res.append(str);}
        return res;
    }

private:
    void mySwap(std::string& str1, std::string& str2) {
        std::string temp = str1;
        str1 = str2;
        str2 = temp;
    }

    int Partition(std::vector<std::string>& arr, int left, int right) {
        int begin = left;
        std::string temp = arr[begin];
        while (left < right) {
            while (left < right && (arr[right] + temp > temp + arr[right])) {right--;}
            while (left < right && (arr[left] + temp <= temp + arr[left])) {left++;}
            if (left < right) {mySwap(arr[left], arr[right]);}
        }
        mySwap(arr[left], arr[begin]);
        return left;
    }

    void quickSort(std::vector<std::string>& arr, int left, int right) {
        if (left >= right) {return;}
        int pivotIndex = Partition(arr, left, right);
        quickSort(arr, left, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, right);
    }
};

int main(int argv, const char** argc) {
    Solution s;
    // empty, only 1 num, only 2 nums
    // repeated nums
    // normal
    std::vector<int> arr{3, 30, 34, 9, 5};
    std::string res = s.minNumber(arr);
    printf("The minimum number of the permutation is %s\n", res.c_str());
    return 0;
}