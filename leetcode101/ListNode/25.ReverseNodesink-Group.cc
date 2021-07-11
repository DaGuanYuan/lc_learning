#include <iostream>
#include <tuple>
#include "../../DataStructure/ListNode.h"

class Solution {
public:
    std::pair<ListNode*, ListNode*> reverse(ListNode* head, ListNode* newHead) {
        if (!head) {return {nullptr, nullptr};}
        ListNode* pre = nullptr, *cur = head, *post = cur->pNext;
        while (post != newHead) {
            cur->pNext = pre;
            pre = cur;
            cur = post;
            post = post->pNext;
        }
        cur->pNext = pre;
        return {cur, head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) {return head;}
        int steps = k;
        ListNode* preHead = new ListNode(-1, head);
        ListNode* pre = preHead, *cur = head, *post = head->pNext, *newHead = cur;
        while (steps--) {
            newHead = newHead->pNext;
            if (!newHead) {break;}
        }
        while (newHead) {
            std::tie(cur, head) = reverse(head, newHead);
            pre->pNext = cur;
            pre = head;
            head->pNext = newHead;
            head = newHead;
            cur = head;
            post = cur->pNext;
            while (steps--) {
                newHead = newHead->pNext;
                if (!newHead) {break;}
            }
        }
        return preHead->pNext;
    }
};