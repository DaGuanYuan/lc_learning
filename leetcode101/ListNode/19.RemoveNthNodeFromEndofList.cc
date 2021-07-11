#include <iostream>
#include "../../DataStructure/ListNode.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) {return head;}
        if (n <= 0) {return nullptr;}
        ListNode* preHead = new ListNode(-1, head);
        ListNode* firstPointer = preHead;
        while (n--) {
            firstPointer = firstPointer->pNext;
            if (!firstPointer) {return nullptr;}
        }
        ListNode* secondPointer = preHead;
        while (firstPointer->pNext) {
            firstPointer = firstPointer->pNext;
            secondPointer = secondPointer->pNext;
        }
        ListNode* temp = secondPointer->pNext;
        secondPointer->pNext = temp->pNext;
        delete temp;
        temp = nullptr;
        return head;
    }
};