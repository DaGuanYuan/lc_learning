#include <iostream>
#include <vector>

class Solution {
public:
    bool checkPossibility(std::vector<int>& arr) {
        if (arr.empty()) {return false;}
        int changeTimes = 0;
        for (int i = 0; i < arr.size() - 1; i++) {
            if (changeTimes > 1) {return false;}
            if (arr[i] > arr[i + 1]) {
                changeTimes++;
                if (i > 0 && arr[i + 1] < arr[i - 1]) {arr[i + 1] = arr[i];}
                else {arr[i] = arr[i + 1];}    
            }
        }
        return changeTimes <= 1;
    }
};