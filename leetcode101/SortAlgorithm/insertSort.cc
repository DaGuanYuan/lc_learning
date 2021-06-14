#include <iostream>
#include <vector>

void insertSort(std::vector<int>& arr) {
    if (arr.empty()) {return;}
    for (int i = 1; i < arr.size(); ++i) {
        int j = i - 1;
        int tempVal = arr[i];
        while (j >= 0 && arr[j] > tempVal) {
            arr[j + 1] = arr[j];
            --j;    
        }
        arr[j + 1] = tempVal;
    }
}

int main(int argc, const char** argv) {
    std::vector<int> arr {4,4,4,2,3,1,1,9};
    printf("Sorted Array:\n");
    insertSort(arr);
    for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); ++it) {
        printf("%d ", *it);
    }
    printf("\n");
    return 0;
}