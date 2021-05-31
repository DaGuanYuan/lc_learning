#include <iostream>
#include <vector>

class Solution {
public:
    std::pair<int, int> findNumsAppearOnlyOnce(std::vector<int>& arr) {
        if (arr.size() <= 1) {return {};}
        int xorRes = 0;
        for (const int& val : arr) {xorRes ^= val;}
        if (xorRes == 0) {
            printf("In array no numbers appear only once\n");
            return {};
        }
        int findBit = 1;
        while ((xorRes & findBit) == 0) {findBit  = (findBit << 1);}
        int res1 = 0;
        int res2 = 0;
        for (const int& val : arr) {
            // Here, you must be very very careful that '==' is advanced than bit operation!!!
            if ((val & findBit) == 0) {res1 ^= val;}
            else {res2 ^= val;}
        }
        return {res1, res2};
    }
};

int main(int argc, const char** argv) {
    Solution s;
    // arr.size() <= 1, arr.size() == 2;
    // array has no numbers appearing only once
    // array has two numbers appearing only once`
    std::vector<int> arr {1, 2, 5, 2};
    std::pair<int, int> res = s.findNumsAppearOnlyOnce(arr);
    printf("%d %d\n" ,res.first, res.second);
    return 0;
}