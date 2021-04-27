#include <iostream>
#include <vector>

class Solution {
public:
    void ReorderOddEven_Solution1(std::vector<int>& arr) {
        if (arr.empty()) {return;}
        int n = arr.size();
        int left = 0;
        int right = n - 1;
        while (left < right) {
            while (left < right && (arr[left] & 0x1) == 1) {left++;}
            while (left < right && (arr[right] & 0x1) == 0) {right--;}
            if (left < right) {
                int temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
            }
        }
    }

    void ReorderOddEven_Solution2(std::vector<int>& arr) {
        if (arr.empty()) {return;}
        int n = arr.size();
        int fast = 0;
        int slow = 0;
        while (fast < n) {
            if ((arr[fast] & 0x1) == 1) {
                int temp = arr[fast];
                arr[fast] = arr[slow];
                arr[slow] = temp;
                slow++;
            }
            fast++;
        }
    }
};

int main(int argc, const char** argv) {
    Solution s;
    std::vector<int> arr{1,2,3,4,5};
    s.ReorderOddEven_Solution2(arr);
    for (int val : arr) {
        printf("%d ", val);
    }
    printf("\n");
    return 0;
}