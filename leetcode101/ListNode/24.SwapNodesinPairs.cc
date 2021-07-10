#include <iostream>
#include "../../DataStructure/ListNode.h"

class Solution {
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->pNext) {return head;}
        ListNode* preHead = new ListNode(INT32_MIN, head);
        ListNode* pre = preHead, *cur = head, *post = head->pNext, *newHead;
        while (cur && cur->pNext) {
            post = cur->pNext;
            newHead = post->pNext;
            post->pNext = cur;
            pre->pNext = post;
            cur->pNext = newHead;
            pre = cur;
            cur = newHead;
        }
        return preHead->pNext;
    }
};