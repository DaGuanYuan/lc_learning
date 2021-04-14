#include "../inc/selectSort.h"

int minIndex(std::vector<int>& arr, int left, int right) {
    int minIdx = left;
    while (left <= right) {
        if (arr[left] < arr[minIdx]) {
            minIdx = left;
        }
        left++;
    }
    return minIdx;
}

void selectSort(std::vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) {return;}
    int left = 0;
    int right = n - 1;
    for (int i = 0; i < n; i++) {
        int minVal = arr[minIndex(arr, i, right)];
        if (minVal == arr[i]) {continue;}
        mySwap(arr[i], arr[minIndex(arr, i, right)]);
    }
}
// selectSort is NOT stable
// A 80   B 80    C 70
// rst:   C  B  A