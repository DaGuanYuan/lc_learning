#include <iostream>
#include <vector>

class Solution {
    std::vector<int> multiply(std::vector<int>& a) {
        if(a.size() == 0) return {};
        std::vector<int> b (a.size(), 0);
        b[0] = 1;
        int tmp = 1;
        for(int i = 1; i < a.size(); i++) {
            b[i] = b[i - 1] * a[i - 1];
        }
        for(int i = a.size() - 2; i >= 0; i--) {
            tmp *= a[i + 1];
            b[i] *= tmp;
        }
        return b;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    return 0;

}
