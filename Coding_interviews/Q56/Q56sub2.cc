#include <iostream>
#include <vector>

class Solution {
public:
    int findSingleNumber(std::vector<int>& arr) {
        if (arr.empty()) {
            printf("The array is Empty! Please check your input!\n");
            return 0;
        }
        // here, we assume arr[i] < 2^31
        std::vector<int> bitArr(31, 0);
        int bitMask = 0x1;
        for (int i = 0; i < 31; i++) {
            for (int val : arr) {bitArr[i] += ((val & bitMask) ? 1 : 0);}
            bitMask = (bitMask << 1);
        }
        int res = 0;
        for (int i = 30; i >= 0; i--) {
            res = res << 1;
            res += bitArr[i] % 3;
        }
        return res;
    }

    int findSingleNumber_FSM(std::vector<int>& arr) {
        if (arr.empty()) {
            printf("The array is Empty! Please check your input!\n");
            return 0;
        }
        int ones = 0;
        int twos = 0;
        for(int num : arr){
            ones = ones ^ num & ~twos;
            twos = twos ^ num & ~ones;
        }
        return ones;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    // We assume all elements present only once or three times, and arr[i] < 2^31
    // arr is empty
    // arr has only one number
    // the singleNum is less/equal/more than 0
    // the repeated number is less/equal/more than 0
    // the singleNum is in the begin/end/mid of the arr
    std::vector<int> arr {1,1,1,2,2,2,3};
    int singleNum = s.findSingleNumber(arr);
    printf("Single number in array is %d\n", singleNum);
    return 0;
}