#include "../inc/bubbleSort.h"

void bubbleSort(std::vector<int>& arr, int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        for (int j = 0; j < arrSize - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                mySwap(arr[j], arr[j + 1]);
            }
        }
    }
}

void bubbleSort(std::vector<int>& arr) {
    if (arr.empty()) {return;}
    int arrSize = arr.size();
    bubbleSort(arr, arrSize);
}