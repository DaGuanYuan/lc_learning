#include <iostream>
#include "../inc/bubbleSort.h"
#include "../inc/countingSort.h"
#include "../inc/heapSort.h"
#include "../inc/insertSort.h"
#include "../inc/mergeSort.h"
#include "../inc/quickSort.h"
#include "../inc/radixSort.h"
#include "../inc/selectSort.h"
#include "../inc/shellSort.h"

void mySwap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void printArr(const std::vector<int>& arr) {
    for (std::vector<int>::const_iterator it = arr.begin(); it != arr.end(); it++) {
        printf("%d ", *it);
    }
    printf("\n");
}

int main(int argc, const char** argv) {
    std::vector<int> arr{5,7,5,2,3,1,4,6,1,8};
    radixSort(arr);
    printArr(arr);
    return 0;
}