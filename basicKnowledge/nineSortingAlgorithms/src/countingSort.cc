#include "../inc/countingSort.h"
#include <tuple>

std::pair<int, int> findMaxandMin(std::vector<int>& arr) {
    int max = -__INT_MAX__;
    int min = __INT_MAX__;
    for (int val : arr) {
        max = val > max ? val : max;
        min = val < min ? val : min;
    }
    return {max, min};
}

void countingSort(std::vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) {return;}
    int minVal, maxVal;
    std::tie(maxVal, minVal) = findMaxandMin(arr);
    int length = maxVal - minVal + 1;
    std::vector<int> countingArr(length, 0);
    for (int val : arr) {countingArr[val - minVal]++;}  //begin from index '0'
    int idx = 0;
    for (int i = 0; i < length; i++) {
        while (countingArr[i]) {
            arr[idx] = i + minVal;
            idx++;
            countingArr[i]--;
        }
    }
}