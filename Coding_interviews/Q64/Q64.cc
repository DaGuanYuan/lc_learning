#include <iostream>

class Solution {
public:
    int res = 0;
    int sumNums(int n) {
        bool x = n > 1 && sumNums(n - 1) > 0;
        res += n;
        return res;
    }
};

// Solution2: Using constructors to construct n times
// Solution3: Using virtual function to terminate recursion
// Solution4: Using function pointer to mock virtual function in C
// Solution5: Using template class

int main(int argc, const char** argv) {
    Solution s;
    // We assume n >= 0;
    // n = 0;
    // n = 1;
    // n > 1
    int n = 10;
    int sum = s.sumNums(n);
    printf("1 + 2 + ... + %d = %d\n", n, sum);
    return 0;
}