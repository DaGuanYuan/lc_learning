#ifndef __RADIXSORT__
#define __RADIXSORT__
#include <vector>

constexpr int BUCKETS = 10;
int maxDigit(const std::vector<int>& arr);
void radixSort(std::vector<int>& arr);

#endif // !__RADIXSORT__