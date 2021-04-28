#include <iostream>
#include "../../DataStructure/ListNode.h"

class Solution {
public:
    ListNode* findKthToTail(ListNode* head, int k) {
        if (!head || k <= 0) {
            printf("Invalid Input\n");
            return nullptr;
        }
        ListNode* pFirst = head;
        ListNode* pSecond = head;

        while (k) {
            if (!pFirst) {
                printf("Invalid Input\n");
                return nullptr;
            }
            pFirst = pFirst->pNext;
            k--;
        }

        while (pFirst) {
            pSecond = pSecond->pNext;
            pFirst = pFirst->pNext;
        }

        return pSecond;
    }
};

int main(int argc, const char** argv) {
    ListNode* l4 = new ListNode(4);
    ListNode* l3 = new ListNode(3, l4);
    ListNode* l2 = new ListNode(2, l3);
    ListNode* l1 = new ListNode(1, l2);
    ListNode* head = l1;
    int k = 1;
    Solution s;
    ListNode* rst = s.findKthToTail(head, k);
    if (rst) {printf("%d\n", rst->val);}
    return 0;
}
