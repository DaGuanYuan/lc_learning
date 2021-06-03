#include <iostream>
#include "../../DataStructure/ListNode.h"

class Solution {
public:
    // Mock
    int lastRemaining_Solution1(int n, int m) {
        if (n <= 0 || m <= 0) {return -1;}
        ListNode* preHead = new ListNode(-1);
        ListNode* pre = preHead;
        for (int i = 0; i < n; i++) {
            ListNode* lastNode = new ListNode(i);
            pre->pNext = lastNode;
            pre = lastNode;
        }
        ListNode* start = preHead->pNext;
        pre->pNext = start;
        int time = n - 1;
        while (time) {
            int step = m - 1;
            while (step) {
                step--;
                start = start->pNext;
            }
            ListNode* temp = start->pNext;
            start->val = temp->val;
            start->pNext = temp->pNext;
            delete temp;
            time--;
        }
        return start->val;
    }

    //Dynamic Processing
    int lastRemaining_Solution2(int n, int m) {
        int x = 0;
        for (int i = 2; i <= n; i++) {
            x = (x + m) % i;
        }
        return x;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    // n <= 0 || m <= 0
    // m > n
    // m = 1, m = n - 1, m = n, m = n + 1
    // n = 1, 2
    // performance test
    int n = 70866;
    int m = 116922;
    int remainingNum = s.lastRemaining_Solution2(n, m);
    printf("The last remaining number is: %d\n", remainingNum);
    return 0;
}