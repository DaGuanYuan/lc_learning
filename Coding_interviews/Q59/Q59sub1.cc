#include <iostream>
#include <vector>
#include <deque>

class Solution {
public:
    std::vector<int> maxValinSlidingWindow(std::vector<int>& arr, int k) {
        std::vector<int> res {};
        int n = arr.size();
        if (n <= 0 || k > n || k <= 0) {return res;}
        std::deque<int> dq;
        // initialize
        for (int i = 0; i < k; i++) {
            while (!dq.empty() && arr[i] > dq.back()) {dq.pop_back();}
            dq.push_back(arr[i]);
        }
        res.push_back(dq.front());

        // add and remove
        for (int i = k; i < n; i++) {
            // add one element
            while (!dq.empty() && arr[i] > dq.back()) {dq.pop_back();}
            dq.push_back(arr[i]);
            //remove one element or not
            if (dq.front() == arr[i - k]) {dq.pop_front();}
            res.push_back(dq.front());
        }
        return res;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    // arr.empty || k > arr.size() || k <= 0;
    // k = 1, k = n;
    // arr is increasing monotonely, decreasing monotonely
    // normal
    std::vector<int> arr {5, 3, 4, 1, 2};
    int k = 3;
    std::vector<int> res = s.maxValinSlidingWindow(arr, k);
    if (res.empty()) {printf("Please check your input!\n");}
    else{
        printf("Maximum value in sliding window when window's size is %d lists below:\n", k);
        printf("[ ");
        for (std::vector<int>::iterator it = res.begin(); it != res.end(); it++) {
            printf("%d ", *it);
        }
        printf("]\n");
    }
    return 0;
}