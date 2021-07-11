#include <iostream>
#include "../../DataStructure/ListNode.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->pNext) {return head;}
        ListNode* pNode = head, *temp = head;
        while (pNode->pNext) {
        pNode = temp;
        temp = pNode->pNext;
            while (pNode->pNext && pNode->val == temp->val) {
                pNode->pNext = temp->pNext;
                delete temp;
                temp = pNode->pNext;
            }
        }
        return head;
    }
};