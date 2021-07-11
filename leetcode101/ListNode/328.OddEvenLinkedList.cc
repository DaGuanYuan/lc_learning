#include <iostream>
#include "../../DataStructure/ListNode.h"

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) {return head;}
        ListNode* odd = head, *even = head->pNext, *evenHead = even;
        while (even && even->pNext) {
            odd->pNext = even->pNext;
            odd = even->pNext;
            even->pNext = odd->pNext;
            even = odd->pNext;
        }
        odd->pNext = evenHead;
        return odd;
    }
};