#include "../inc/mergeSort.h"

void mergeTwoArray(std::vector<int>& arr, 
                   std::vector<int>& tempArr, 
                   int left, 
                   int mid, 
                   int right) {
    int l_pos = left;
    int r_pos = mid + 1;
    int pos = left;
    while (l_pos <= mid && r_pos <= right) {
        while (l_pos <= mid && r_pos <= right && arr[l_pos] <= arr[r_pos]) {
            tempArr[pos++] = arr[l_pos++];
        }
        while (l_pos <= mid && r_pos <= right && arr[l_pos] > arr[r_pos]) {
            tempArr[pos++] = arr[r_pos++];
        }
    }
    while (l_pos <= mid) {
        tempArr[pos++] = arr[l_pos++];
    }
    while (r_pos <= right) {
        tempArr[pos++] = arr[r_pos++];
    }
    while (left <= right) {
        arr[left] = tempArr[left];
        left++;
    }

}

void mergeSort(std::vector<int>& arr, std::vector<int>& tempArr, int left, int right) {
    if (left >= right) {return;}
    int mid = left + ((right - left) >> 1);
    mergeSort(arr, tempArr, left, mid);
    mergeSort(arr, tempArr, mid + 1, right);
    mergeTwoArray(arr, tempArr, left, mid, right);
}

void mergeSort(std::vector<int>& arr) {
    if (arr.empty()) {return;}
    int n = arr.size();
    std::vector<int> tempArr(n, 0);
    mergeSort(arr, tempArr, 0, n - 1);
}