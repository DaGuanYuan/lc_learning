#include <iostream>
#include <vector>

class Solution {
public:
    int findGreaterSumofSubArray(std::vector<int>& arr) {
        if (arr.empty()) {
            printf("The array is empty!\n");
            return INT32_MIN;
        }
        int curSum = 0;
        int maxSum = INT32_MIN;
        for (const int& val : arr) {
            curSum += val;
            maxSum = std::max(maxSum, curSum);
            if (curSum < 0) {curSum = 0;}
        };
        return maxSum;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    // empty
    // all elements are negative/positive
    // normal
    std::vector<int> arr {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int maxSumofSubArray = s.findGreaterSumofSubArray(arr);
    printf("The max sum of arr's subarray is: %d\n", maxSumofSubArray);
    return 0;
}