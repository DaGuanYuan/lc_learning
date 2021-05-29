#include <iostream>
#include <vector>

class Solution {
public:
    int inversePairs(std::vector<int>& arr) {
        if (arr.empty()) {return 0;}
        std::vector<int> tempArr(arr.size(), 0);
        inversePairsCore(arr, tempArr, 0, arr.size() - 1);
        return this->count;
    }
    
private:
    int count = 0;

    void mergeAndCountInversePairs(std::vector<int>& arr,
                                   std::vector<int>& tempArr,
                                   int left,
                                   int mid,
                                   int right) {
        int l_pos = left;
        int r_pos = mid + 1;
        int pos = l_pos;
        while (l_pos <= mid && r_pos <= right) {
            while (l_pos <= mid && r_pos <= right && arr[l_pos] > arr[r_pos]) {
                tempArr[pos++] = arr[r_pos++];
                this->count += (mid - l_pos + 1);

            }
            while (l_pos <= mid && r_pos <= right && arr[l_pos] <= arr[r_pos]) {
                tempArr[pos++] = arr[l_pos++];
            }
        }
        while (l_pos <= mid) {tempArr[pos++] = arr[l_pos++];}
        while (r_pos <= right) {tempArr[pos++] = arr[r_pos++];}
        while (left <= right) {
            arr[left] = tempArr[left];
            left++;
        }
    }
    

    void inversePairsCore(std::vector<int>& arr, std::vector<int>& tempArr, int left, int right) {
        if (left >= right) {return;}
        int mid = left + ((right - left) >> 1);
        inversePairsCore(arr, tempArr, left, mid);
        inversePairsCore(arr, tempArr, mid + 1, right);
        mergeAndCountInversePairs(arr, tempArr, left, mid, right);
    }
};

int main(int argc, const char** argv) {
    Solution s;
    // arr is empty
    // arr has only one element
    // arr does not have inverse pairs
    // arr has repeated element
    // all the elements in arr is as the same
    std::vector<int> arr {1, 4, 5, 9, 2, 3, 7, 8};
    int count = s.inversePairs(arr);
    printf("There're %d inverse pairs in array\n", count);
    return 0;
}