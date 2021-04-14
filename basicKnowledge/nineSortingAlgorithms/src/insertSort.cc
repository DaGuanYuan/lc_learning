#include "../inc/insertSort.h"

void insertSort(std::vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) {return;}
    for (int i = 1; i < n; i++) {
        int j = i;
        int temp = arr[j];
        while (arr[j - 1] > temp && j > 0) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = temp;
    }
}
// Whether insertSort is stable or not depended upon YOUR CODE
// a[j - 1] >= temp;    vs     a[j - 1] > temp;