#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

class Solution {
public:
    bool isContinuous_Solution1(std::vector<int>& arr) {
        if (arr.empty()) {return false;}
        std::sort(arr.begin(), arr.end());
        int joker = 0;
        int i = 0;
        while (i < 5 && arr[i] == 0) {
            i++;
            joker++;
        }
        int cur = arr[i];
        int pre = arr[i] - 1;
        while (i < 5) {
            cur = arr[i++];
            while (cur != pre + 1) {
                if (joker) {
                    joker--;
                    pre++;
                }
                else {return false;}
            }
            pre = cur;
        }
        return true;
    }

    // notice that if arr has repeated numbers not equaling to 0 -> false
    // if max - min > 4 ->false
    bool isContinuous_Solution2(std::vector<int>& arr) {
        if (arr.empty()) {return false;}
        std::sort(arr.begin(), arr.end());
        int joker = 0;
        for (int i = 0; i < 4; i++) {
            if (arr[i] == 0) {joker++;}
            else if (arr[i] == arr[i + 1]) {return false;}
        }
        return (arr[4] - arr[joker]) <= 4;
    }

    bool isContinuous_Solution3(std::vector<int>& arr) {
        if (arr.empty()) {return false;}
        std::set<int> st;
        int max = INT32_MIN;
        int min = INT32_MAX;
        for (const int val : arr) {
            if (val == 0) {continue;}
            if (st.find(val) != st.end()) {return false;}
            st.insert(val);
            max = val > max ? val : max;
            min = val < min ? val : min;
        }
        return (max - min) <= 4;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    // Here, we assume arr.size() = 5 && elements in array range from 0 ~ 13
    // array has 1 / 2 jokers
    // array does not have jokers
    // array has repeated number
    // normal test
    std::vector<int> arr {0, 0, 3, 4, 7};
    bool continuous = s.isContinuous_Solution1(arr);
    if (continuous) {printf("The array is continuous\n");}
    else {printf("The array is discrete\n");}
    return 0;
}