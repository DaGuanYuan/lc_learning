#include <iostream>
#include <vector>

void mySwap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(std::vector<int>& arr) {
    if (arr.empty()) {return;}
    for (int i = arr.size() - 1; i >= 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (arr[j] > arr[j + 1]) {mySwap(arr[j], arr[j + 1]);}
        }
    }
}

int main(int argc, const char** argv) {
    std::vector<int> arr {1,1,1,1,1,1,7,7,7,7,4,2,3,6,6,6,5};
    bubbleSort(arr);
    printf("Sorted Array:\n");
    for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); ++it) {
        printf("%d ", *it);
    }
    printf("\n");
    return 0;
}