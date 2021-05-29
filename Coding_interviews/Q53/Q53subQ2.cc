#include <iostream>
#include <vector>

class Solution {
public:
    int missingNumber(std::vector<int>& arr) {
        if (arr.empty()) {return 0;}
        int left = 0;
        int right = arr.size() - 1;
        int mid = 0;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (arr[mid] == mid) {left = mid + 1;}
            else {right = mid - 1;}
        }
        return left;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    // arr is empty
    // arr has only one element, arr = [1] or arr = [0]
    // arr has two elements
    // normal, missing number is at the begin/mid/end of the arr
    // array is not obey to the rule (not test)
    std::vector<int> arr {0, 1, 2, 3, 5, 6, 7, 8};
    int missingNum = s.missingNumber(arr);
    printf("The missing number in array is %d\n", missingNum);
    return 0;
}