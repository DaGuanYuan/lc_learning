#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int> > findContinuousSequence(int n) {
        if (n <= 0) {
            printf("Invalid Input!\n");
            return {};
        }
        std::vector<int> temp;
        std::vector<std::vector<int> > res;
        int left = 1;
        int right = 1;
        int sum = 1;
        // left <= right is not necessary since right <= (n+1)/2, only if sum > n, left++
        while (right <= (n + 1) / 2) {
            if (sum == n) {
                temp.clear();
                for (int j = left; j <= right; j++) {temp.push_back(j);}
                res.push_back(temp);
            }
            // <= for simplifying == n amd < n
            if (sum <= n) {
                right++;
                sum += right;
            }
            if (sum > n) {
                sum -= left;
                left++;
            }
        }
        return res;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    // n <= 0;
    // n = 1, 3;
    // n = 2;
    // n > 3;
    int n = 2;
    std::vector<std::vector<int> > res = s.findContinuousSequence(n);
    if (res.empty()) {printf("Sorry, no Continuous sequences can add up to %d\n", n);}
    else {
        printf("Continuous sequences that added up to %d are showed below:\n", n);
        for (std::vector<std::vector<int> >::iterator it1 = res.begin(); it1 != res.end(); it1++) {
            printf("[ ");
            for (std::vector<int>::iterator it2 = it1->begin(); it2 != it1->end(); it2++) {
                printf("%d ", *it2);
            }
            printf("]\n");
        }
    }
    return 0;
}