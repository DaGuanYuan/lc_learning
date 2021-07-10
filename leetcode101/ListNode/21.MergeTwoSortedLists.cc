#include <iostream>
#include "../../DataStructure/ListNode.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* preHead = new ListNode(INT32_MIN, l1);
        ListNode* pre = preHead;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                pre->pNext = l1;
                l1 = l1->pNext;
            } else {
                pre->pNext = l2;
                l2 = l2->pNext;
            }
            pre = pre->pNext;
        }
        pre->pNext = l1 ? l1 : l2;
        return preHead->pNext;
    }

    ListNode* mergeTwoListsRecursively(ListNode* l1, ListNode* l2) {
        if (!l1) {return l2;}
        if (!l2) {return l1;}
        if (l1->val <= l2->val) {
            l1->pNext = mergeTwoListsRecursively(l1->pNext, l2);
            return l1;
        }
        l2->pNext = mergeTwoListsRecursively(l1, l2->pNext);
        return l2;
    }
};