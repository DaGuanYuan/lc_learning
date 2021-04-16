#include <iostream>
#include "../../DataStructure/ListNode.h"
#include <stack>

//Q6 Solution
class Solution {
public:
    void PrintListReversingly_Iteratively(ListNode* phead) {
        if (phead == nullptr) {
            printf("List is not existing\n");
            return;
        }
        std::stack<int> stk;
        ListNode* p = phead;
        while (p != nullptr) {
            stk.push(p->val);
            p = p->pNext;
        }
        while (!stk.empty()) {
            printf("%d ", stk.top());
            stk.pop();
        }
        printf("\n");
    }

    void PrintListReversingly_Iteratively_Method2(ListNode* phead) {
        if (phead == nullptr) {return;}
        PrintListReversingly_Iteratively_Method2(phead->pNext);
        printf("%d  ", phead->val);
    }
};
int main() {
    ListNode *p6 = new ListNode(7);
    ListNode *p5 = new ListNode(3, p6);
    ListNode *p4 = new ListNode(1, p5);
    ListNode *p3 = new ListNode(6, p4);
    ListNode *p2 = new ListNode(2, p3);
    ListNode *p1 = new ListNode(9, p2);
    ListNode *p0 = new ListNode(8, p1);
    ListNode *phead = p0;
    Solution s;
    s.PrintListReversingly_Iteratively_Method2(phead);
    printf("\n");

    return 0;
}