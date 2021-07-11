#include <iostream>
#include "../../DataStructure/ListNode.h"

class Solution {
public:
    ListNode* mergerTwoSortedList(ListNode* l1, ListNode* l2) {
        ListNode* preHead = new ListNode(INT32_MAX);
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

    ListNode* sortList(ListNode* head) {
        if (!head || !head->pNext) {return head;}
        ListNode* slowPointer = head, *fastPointer = head;
        while (fastPointer->pNext && fastPointer->pNext->pNext) {
            slowPointer = slowPointer->pNext;
            fastPointer = fastPointer->pNext->pNext;
        }
        ListNode* newHead = slowPointer->pNext;
        slowPointer->pNext = nullptr;
        ListNode* firstHead = sortList(head);
        ListNode* secondHead = sortList(newHead);
        ListNode* res = mergerTwoSortedList(firstHead, secondHead);
        return res;
    }
};