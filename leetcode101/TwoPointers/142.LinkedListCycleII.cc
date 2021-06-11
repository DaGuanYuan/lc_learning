#include <iostream>
#include "../../DataStructure/ListNode.h"

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slowPointer = head, *fastPointer = head;
        while (1) {
            if (!fastPointer || !fastPointer->pNext) {return nullptr;}
            slowPointer = slowPointer->pNext;
            fastPointer = fastPointer->pNext->pNext;
            if (slowPointer == fastPointer) {break;}
        }
        slowPointer = head;
        while (slowPointer != fastPointer) {
            slowPointer = slowPointer->pNext;
            fastPointer = fastPointer->pNext;
        }
        return slowPointer;
    }
};

// happy birthday!!!!