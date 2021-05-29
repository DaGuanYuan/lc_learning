#include <iostream>
#include <vector>

class Solution {
public:
    int findNumSameAsIndex(std::vector<int>& arr) {
        if (arr.empty()) {
            printf("The array is empty!\n");
            return 0;
        }
        int left = 0;
        int right = arr.size() - 1;
        int mid = 0;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (arr[mid] == mid) {return mid;}
            else if (arr[mid] > mid) {right = mid - 1;}
            else {left = mid + 1;}
        }
        printf("There is no elements that values are the same as indexes in the array!\n");
        return 0;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    // arr.empty()
    // arr has only one/two elements
    // target is at the begin/mid/end of the array
    // not only one target
    std::vector<int> arr {-3, -1, 1, 3, 5};
    int targetVal = s.findNumSameAsIndex(arr);
    printf("%d in array has the same value and index\n", targetVal);
    return 0;
}