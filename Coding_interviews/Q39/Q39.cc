#include <iostream>
#include <vector>

class Solution {
public:
    // Boyer-Moore Algorithm
    int findMajorityNum(std::vector<int>& arr) {
        int candidate = INT32_MAX;
        int voteCatching = 0;
        for (const int& val : arr) {
            if (voteCatching == 0) {
                candidate = val;
                voteCatching++;
            }
            else if (val != candidate) {voteCatching--;}
            else {voteCatching++;}
        }
        if (!checkValidity(arr, candidate)) {return INT32_MIN;}
        return candidate;
    }

    bool checkValidity(std::vector<int>& arr, int candidate) {
        if (arr.empty()) {return false;}
        int num = 0;
        for (const int& val : arr) {if (val == candidate) {num++;}}
        if ((num << 1) < arr.size()) {return false;}
        return true;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    // empty
    // has repeated but not major num
    // has majority num
    std::vector<int> arr {1,2,2,4,2};
    int majorityVal = s.findMajorityNum(arr);
    if (majorityVal == INT32_MIN) {printf("Invalid Input! Please have a check!\n");}
    else {printf("The majority number is %d\n", majorityVal);}
    return 0;
}