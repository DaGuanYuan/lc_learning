#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> multiply(std::vector<int>& a) {
        if (a.empty()) {return {};}
        int n = a.size();
        std::vector<int> b(n, 1);
        for (int i = 1; i <= n - 1; i++) {b[i] = b[i - 1] * a[i - 1];}
        int temp = 1;
        for (int i = 2; i <= n; i++) {
            temp *= a[n - i + 1];
            b[n - i] *= temp;
        }
        return b;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    // a is empty
    // a has only one element
    // a contains positive, negative and 0
    std::vector<int> a {1, 2, 3, 4, 5};
    std::vector<int> res = s.multiply(a);
    if (res.empty()) {printf("The input is empty, Please have a check!\n");}
    else {
        printf("The mulitply array is:\n");
        for (std::vector<int>::iterator it = res.begin(); it != res.end(); it++) {
            printf("%d ", *it);
        }
        printf("\n");
    } 
    return 0;

}
