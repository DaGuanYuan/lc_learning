#include "../inc/shellSort.h"

void shellSort(std::vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) {return;}
    for (int gap = n / 2; gap >= 1; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int j = i;
            int temp = arr[j];
            while (arr[j - gap] > temp && j >= gap) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}