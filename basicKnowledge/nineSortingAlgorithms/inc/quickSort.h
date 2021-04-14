#ifndef __QUICKSORT__
#define __QUICKSORT__
#include <vector>

void mySwap(int& a, int& b);
int Partition(std::vector<int>& arr, int left, int right);
void quickSort(std::vector<int>& arr, int left, int right);
void quickSort(std::vector<int>& arr);

#endif // __QUICKSORT__