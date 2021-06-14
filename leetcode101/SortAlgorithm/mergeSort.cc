#include <iostream>
#include <vector>

void mergeTwoSortedArr(std::vector<int>& arr,
                       std::vector<int>& tempArr,
                       int left,
                       int mid,
                       int right) {
    int l_pos = left;
    int r_pos = mid + 1;
    int pos = left;
    while (l_pos <= mid && r_pos <= right) {
        if (l_pos <= mid &&
            r_pos <= right && 
            arr[l_pos] <= arr[r_pos]) {tempArr[pos++] = arr[l_pos++];}
        else {tempArr[pos++] = arr[r_pos++];}
    }
    while (l_pos <= mid) {tempArr[pos++] = arr[l_pos++];}
    while (r_pos <= right) {tempArr[pos++] = arr[r_pos++];}
    while (left <= right) {arr[left++] = tempArr[left];}
}

void mergeSort(std::vector<int>& arr,
               std::vector<int>& tempArr,
               int left,
               int right) {
    if (left >= right) {return;}
    int mid = left + ((right - left) >> 1);
    mergeSort(arr, tempArr, left, mid);
    mergeSort(arr, tempArr, mid + 1, right);
    mergeTwoSortedArr(arr, tempArr, left, mid, right);
}

void mergeSort(std::vector<int>& arr) {
    if (arr.empty()) {return;}
    std::vector<int> tempArr;
    tempArr.resize(arr.size());
    mergeSort(arr, tempArr, 0, arr.size() - 1);
}

int main(int argc, const char** argv) {
    std::vector<int> arr {2,2,2,2,2,2,8,1,7,7,7,7,6};
    mergeSort(arr);
    printf("The sorted array is showed below:\n");
    for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); it++) {
        printf("%d ", *it);
    }
    printf("\n");
    return 0;
}