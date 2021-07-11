#include <iostream>
#include "../../DataStructure/ListNode.h"

class Solution {
public:
    ListNode* reverse(ListNode* head, ListNode* newHead) {
        if (!head) {return nullptr;}
        ListNode* pre = nullptr, *cur = head, *post = cur->pNext;
        while (post != newHead) {
            cur->pNext = pre;
            pre = cur;
            cur = post;
            post = post->pNext;
        }
        cur->pNext = pre;
        return cur;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) {return head;}
        int steps = 0;
        ListNode* preHead = new ListNode(-1, head);
        ListNode* pre = preHead, *cur = head, *post = head->pNext, *newHead = cur;
        while (!steps) {
            steps = k;
            while (steps) {
                newHead = newHead->pNext;
                if (!newHead) {break;}
                --steps;    //calculate steps after update newHead
                // advantage: k == 0 || k == 1 || k > 1 indicates
                // three different situations (wow, I'm so smart!)
            }
            if (steps) {break;}
            cur = reverse(head, newHead);
            pre->pNext = cur;
            pre = head;
            head->pNext = newHead;
            head = newHead;
            cur = head;
            post = cur->pNext;
        }
        if (steps == 1) {
            cur = reverse(head, newHead);
            pre->pNext = cur;
            pre = head;
            head->pNext = newHead;
        }
        return preHead->pNext;
    }
};