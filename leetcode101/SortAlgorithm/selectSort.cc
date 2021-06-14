#include <iostream>
#include <vector>

void mySwap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void selectSort(std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        int pos = i;
        int min = INT32_MAX;
        for (int j = i; j < arr.size(); ++j) {
            if (arr[j] < min) {
                min = arr[j];
                pos = j;
            }
        } 
        mySwap(arr[i], arr[pos]);
    }
}

int main(int argc, const char** argv) {
    std::vector<int> arr {2,2,1,7,2,1,5,6,4,3};
    selectSort(arr);
    printf("Sorted Array:\n");
    for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); ++it) {
        printf("%d ", *it);
    }
    printf("\n");
    return 0;
}