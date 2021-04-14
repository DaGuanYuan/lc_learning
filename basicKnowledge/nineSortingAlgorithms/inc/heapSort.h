#ifndef __HEAPSORT__
#define __HEAPSORT
#include <vector>

void mySwap(int& a, int& b);
void adjustMaxHeap(std::vector<int>& arr, int heapSize, int index);
void maxHeapInit(std::vector<int>& arr, int heapSize);
void heapSort(std::vector<int>& arr, int heapSize);
void heapSort(std::vector<int>& arr);

#endif // __HEAPSORT__
