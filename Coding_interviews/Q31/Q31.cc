#include <iostream>
#include <vector>
#include <stack>

class Solution {
public:
    bool isPopOrder(std::vector<int>& sPush, std::vector<int>& sPop) {
        if (sPush.size() != sPop.size()) {return false;}
        if (sPush.empty()) {return true;}
        std::stack<int> stk;
        int i = 0;
        for (const int val : sPush) {
            stk.push(val);
            while (!stk.empty() && stk.top() == sPop[i]) {
                stk.pop();
                i++;
            }
        }
        return stk.empty();
    }
};

int main(int argc, const char** argv) {
    Solution s;
    // sPush.empty() || sPop.empty() || sPush.size() != sPop.size()
    // matched
    // not matched
    // totally inorder sPush = [1,2,3,4] && sPop = [1,2,3,4]
    // size = 1
    std::vector<int> sPush {1, 2, 3, 4, 5};
    std::vector<int> sPop {1, 2, 3, 4, 5};
    if (s.isPopOrder(sPush, sPop)) {printf("Is Pop Order!\n");}
    else {printf("Is NOT Pop Order!\n");}
    return 0;
}