#include <iostream>
#include <vector>

class Solution {
public:
    // In this Solution, if vector arr = {1,1,1,1,1,1}, time complexity will degenerate to O(n)
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

    int countK_Solution2(std::vector<int>& arr, int k) {
        if (arr.empty()) {
            printf("The array is empty! please have a check!\n");
            return 0;
        }
        int left = 0;
        int right = arr.size() - 1;
        int mid = 0;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (arr[mid] >= k) {right = mid - 1;}
            else {left = mid + 1;}
        }
        int leftBoundary = right;

        left = 0;
        right = arr.size() - 1;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (arr[mid] > k) {right = mid - 1;}
            else {left = mid + 1;}
        }
        int rightBoundary = left;

        return rightBoundary - leftBoundary -1;
    }

    // simplify solution2 by only finding right boundaries
    // The number of k = rightBoudary_k - rightBoundary_k-1
    int countK_Solution3(std::vector<int>& arr, int k) {
        if (arr.empty()) {
            printf("The array is empty! please have a check!\n");
            return 0;
        }
        return rightBoundaryIndex(arr, k) - rightBoundaryIndex(arr, k - 1);
    }

    int rightBoundaryIndex(std::vector<int>& arr, int k) {
        int left = 0;
        int right = arr.size() - 1;
        int mid = 0;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (arr[mid] <= k) {left = mid + 1;}
            else {right = mid - 1;}
        }
        return left;
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