#include "../inc/heapSort.h"

void adjustMaxHeap(std::vector<int>& arr, int heapSize, int index) {
    int temp = arr[index];
    for (int i = index * 2 + 1; i < heapSize; i = i * 2 + 1) {
        if (i + 1 < heapSize && arr[i + 1] > arr[i]) {i++;}
        if (arr[i] > temp) {
            arr[index] = arr[i];
            index = i;
        }
    }
    arr[index] = temp;
}

void maxHeapInit(std::vector<int>& arr, int heapSize){
    for (int i = heapSize / 2 - 1; i >= 0; i--) {
        adjustMaxHeap(arr, heapSize, i);
    }
}

void heapSort(std::vector<int>& arr, int heapSize) {
    maxHeapInit(arr, heapSize);
    for (int i = heapSize - 1; i > 0; i--) {
        mySwap(arr[0], arr[i]);
        adjustMaxHeap(arr, i, 0);
    }
}

void heapSort(std::vector<int>& arr) {
    if (arr.empty()) {return;}
    int n = arr.size();
    heapSort(arr, n);
}