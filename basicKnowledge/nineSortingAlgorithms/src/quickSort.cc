#include "../inc/quickSort.h"

int Partition(std::vector<int>& arr, int left, int right) {
    int begin = left;
    int end = right;
    int pivotVal = arr[left];
    while (begin < end) {
        while (begin < end && pivotVal < arr[end]) {
            end--;
        }
        while (begin < end && pivotVal >= arr[begin]) {
            begin++;
        }
        if (begin < end) {
            mySwap (arr[begin], arr[end]);
        }
    }
    mySwap(arr[begin], arr[left]);
    return begin;
}

void quickSort(std::vector<int>& arr, int left, int right) {
    if (left >= right) {return;}
    int pivotIndex = Partition(arr, left, right);
    quickSort(arr, left, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, right);
}

void quickSort(std::vector<int>& arr) {
    if (arr.empty()) {return;}
    int n = arr.size();
    quickSort(arr, 0, n - 1);
}