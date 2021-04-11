#include <iostream>
#include "../DataStucture/LinkNode.h"
#include <stack>

//Q6 Solution
class Solution {
public:
    void PrintListReversingly_Iteratively(LinkNode* phead) {
        if (phead == nullptr) {
            printf("List is not existing\n");
            return;
        }
        std::stack<int> stk;
        LinkNode* p = phead;
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

    void PrintListReversingly_Iteratively_Method2(LinkNode* phead) {
        if (phead == nullptr) {return;}
        PrintListReversingly_Iteratively_Method2(phead->pNext);
        printf("%d  ", phead->val);
    }
};
int main() {
    LinkNode *p6 = new LinkNode(7);
    LinkNode *p5 = new LinkNode(3, p6);
    LinkNode *p4 = new LinkNode(1, p5);
    LinkNode *p3 = new LinkNode(6, p4);
    LinkNode *p2 = new LinkNode(2, p3);
    LinkNode *p1 = new LinkNode(9, p2);
    LinkNode *p0 = new LinkNode(8, p1);
    LinkNode *phead = p0;
    Solution s;
    s.PrintListReversingly_Iteratively_Method2(phead);
    printf("\n");

    return 0;
}