#include <iostream>
#include <vector>

void shellSort(std::vector<int>& arr) {
    if (arr.empty()) {return;}
    for (int gap = arr.size() / 2; gap >= 1; gap /= 2) {
        for (int i = gap; i < arr.size() / gap; i++) {
            int j = i - gap;
            int temp = arr[i];
            while (j >= 0 && temp < arr[j]) {
                arr[j + gap] = arr[j];
                j -= gap;
            }
            arr[j + gap] = temp;
        }
    }
}

int main(int argc, const char** argv) {
    std::vector<int> arr {5,2,2,2,1,5,4,3,3,7};
    shellSort(arr);
    printf("Sorted Array:\n");
    for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); ++it) {
        printf("%d ", *it);
    }
    printf("\n");
    return 0;
}