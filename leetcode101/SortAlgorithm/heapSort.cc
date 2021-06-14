#include <iostream>
#include <vector>
void mySwap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void adjustHeap(std::vector<int>& arr, int heapSize, int pos) {
    int temp = arr[pos];
    for (int i = 2 * pos + 1; i < heapSize; i = 2 * i + 1) {
        if (i + 1 < heapSize && arr[i + 1] > arr[i]) {++i;}
        if (arr[i] > temp) {
            arr[pos] = arr[i];
            pos = i;
        } else {break;}
    }
    arr[pos] = temp;
}

void initMaxHeap(std::vector<int>& arr, int heapSize) {
    for (int i = heapSize / 2 - 1; i >= 0; i--) {
        adjustHeap(arr, heapSize, i);
    }
}

void heapSort(std::vector<int>& arr) {
    if (arr.empty()) {return;}
    int n = arr.size();
    initMaxHeap(arr, n);
    for (int i = n - 1; i > 0; --i) {
        mySwap(arr[i], arr[0]);
        adjustHeap(arr, i, 0);
    }
}

int main(int argc, const char** argv) {
    std::vector<int> arr {5,2,2,2,1,5,4,3,3,7};
    heapSort(arr);
    printf("Sorted Array:\n");
    for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); ++it) {
        printf("%d ", *it);
    }
    printf("\n");
    return 0;
}