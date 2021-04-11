#include "iostream"
#include "vector"

#define ERROR false

class Solution {
public:
    int Duplicate(std::vector<int>& arr, int n);
};

int Solution::Duplicate(std::vector<int>& arr, int n) {
    for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); it++) {
        if (*it > n) {
            printf("ERROE, Out of range!");
            return static_cast<int>(ERROR);
        }
    }
    std::vector<int> support(n+1, n+1);
    for (int i = 0; i <= n; i++) {
        if (support[arr[i]] != arr[i]) {
            support[arr[i]] = arr[i];
        }
        else
        {
            return arr[i];
        }
        
    }


    return 0;
}

int main() {
    // int n = 10;
    // std::vector<int> arr(n+1, n+1);
    // for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); it++) {
    //     std::cout << *it << std::endl;
    // }
    std::vector<int> array{5,9,4,3,2,4};
    int n = array.size() - 1;
    Solution s;
    int result = s.Duplicate(array, n);
    printf("The duplicated number is %d\n", result);
    return 0;
}