#include <iostream>
#include <vector>

void mySwap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int Partition(std::vector<int>& arr, int left, int right) {
    int pivotVal = arr[left];
    int begin = left;
    while(left < right) {
        while (left < right && arr[right] > pivotVal) {--right;}
        while (left < right && arr[left] <= pivotVal) {++left;}
        if (left < right) {mySwap(arr[left], arr[right]);}
    }
    mySwap(arr[begin], arr[left]);
    return left;
}

void quickSort(std::vector<int>& arr, int left, int right) {
    if (left >= right) {return;}
    int pivotIndex = Partition(arr, left, right);
    quickSort(arr, left, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, right);
}

void quickSort(std::vector<int>& arr) {
    if (arr.empty()) {return;}
    quickSort(arr, 0, arr.size() - 1);
}

int main(int argc, const char** argv) {
    std::vector<int> arr {2,2,2,2,2,2,1,9,7,7,7,7,4,3};
    quickSort(arr);
    printf("Sorted result:\n");
    for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); ++it) {
        printf("%d ", *it);
    }
    printf("\n");
    return 0;
}