#include <iostream>
#include <vector>
#include <exception>

class Solution {
public:
    int minRotationArr(const std::vector<int>& arr) {
        if (arr.empty()) {return -1;}
        int n = arr.size();
        int left = 0;
        int right = n - 1;
        if (arr[left] < arr[right]) {return arr[left];} //rotate 0 or n numbers
        int mid = left + ((right - left) >> 1);
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (arr[mid] > arr[right]) {left = mid + 1;}
            else if (arr[mid] < arr[right]) {right = mid;}
            else {right--;}
        }
        return arr[mid];
    }
};

int main(int argc, const char** argv) {
    Solution s;
    std::vector<int> arr{1, 1, 1, 0 ,1, 1};
    printf("%d\n", s.minRotationArr(arr));
    return 0;
}