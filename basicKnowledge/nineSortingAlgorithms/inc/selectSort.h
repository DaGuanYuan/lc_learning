#ifndef __SELECTSORT__
#define __SELECTSORT__
#include <vector>

void mySwap(int& a, int& b);
int minIndex(std::vector<int>& arr, int left, int right);
void selectSort(std::vector<int>& arr);

#endif // __SELECTSORT__