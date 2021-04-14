#ifndef __MERGESORT__
#define __MERGESORT
#include <vector>

void mergeTwoArray(std::vector<int>& arr, 
                   std::vector<int>& tempArr, 
                   int left, 
                   int mid, 
                   int right);
void mergeSort(std::vector<int>& arr, int left, int right);
void mergeSort(std::vector<int>& arr);

#endif // __MERGESORT__