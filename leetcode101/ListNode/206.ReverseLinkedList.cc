#include <iostream>
#include "../../DataStructure/ListNode.h"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->pNext) {return head;}
        ListNode* prev = nullptr, *cur = head, *post = head->pNext;
        while (post) {
            cur->pNext = prev;
            prev = cur;
            cur = post;
            post = post->pNext;
        }
        cur->pNext = prev;
        return cur;
    }

    ListNode* reverseList_recursively(ListNode* head) {
        if (!head || !head->pNext) {return head;}
        ListNode* headAfterReversing = reverseList_recursively(head->pNext);
        ListNode* temp = headAfterReversing;
        while (temp->pNext) {
            temp = temp->pNext;
        }
        temp->pNext = head;
        return headAfterReversing;
    }

    ListNode* reverseList_recursively2(ListNode* head) {
        if (!head) {return prev;}
        ListNode* next = head->pNext;
        head->pNext = prev;
        prev = head;
        return reverseList_recursively2(next);
    }
    
    ListNode* prev = nullptr;
};