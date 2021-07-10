#include <iostream>
#include "../../DataStructure/ListNode.h"

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (!headA || !headB) {return nullptr;}
        ListNode* l1 = headA, *l2 = headB;
        while (l1 != l2) {
            l1 = l1 ? l1->pNext : headB;
            l2 = l2 ? l2->pNext : headA;
        }
        return l1;
    }
};