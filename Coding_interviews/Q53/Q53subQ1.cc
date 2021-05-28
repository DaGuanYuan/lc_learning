#include <iostream>
#include <vector>

class Solution {
public:
    int countK(std::vector<int>& arr, int k) {
        if (arr.empty()) {
            printf("The array is empty! please have a check!\n");
            return 0;
        }
        int left = 0;
        int right = arr.size() - 1;
        int count = 0;
        int mid = 0;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (arr[mid] > k) {right = mid - 1;}
            else if (arr[mid] < k) {left = mid + 1;}
            else {
                count++;
                left = mid + 1;
                right = mid - 1;
                while (left < arr.size() && arr[left] == k) {
                    left++;
                    count++;
                } 
                while (right >= 0 && arr[right] == k) {
                    right--;
                    count++;
                }
                break;
            }
        }
        return count;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    // arr.empty() || only one value
    // k is at the begin/mid/end of arr
    // k is not existing in arr
    // k exist only once/not once
    std::vector<int> arr {1, 2, 3, 3, 3, 3, 3, 4, 5};
    int k = 0;
    int numberofK = s.countK(arr, k);
    printf("In The array, the number of %d is: %d\n", k, numberofK);
    return 0;
}