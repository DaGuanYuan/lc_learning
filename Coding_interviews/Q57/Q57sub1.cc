#include <iostream>
#include <vector>

class Solution {
public:
    bool findSumofNumbersEqualtoTarget(std::vector<int>& arr, int target) {
        if (arr.size() <= 1) {return false;}
        int left = 0;
        int right = arr.size() - 1;
        int sum = 0;
        while (left < right) {
            sum = arr[left] + arr[right];
            if (sum == target) {return true;}
            else if (sum > target) {right--;}
            else {left++;}
        }
        return false;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    // Notice: array is in order, otherwise, sorting should be excuted to maintain orderness
    // arr.size() <= 1;
    // array has repeated elements or all elements in array are unique
    // true / false
    std::vector<int> arr {1, 2, 3, 4, 5, 6, 7};
    int target = 5;
    bool hasSumofNumEqualtoTarget = s.findSumofNumbersEqualtoTarget(arr, target);
    if (hasSumofNumEqualtoTarget) {printf("In array exists two numbers that equal to %d\n", target);}
    else {printf("In array NOT exists two numbers that equal to %d\n", target);}
    return 0;
}