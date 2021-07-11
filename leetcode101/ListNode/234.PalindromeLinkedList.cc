#include <iostream>
#include "../../DataStructure/ListNode.h"

class Solution {
public:
    void reverseList(ListNode** head) {
        if (!(*head) || !((*head)->pNext)) {return;}
        ListNode* pre = nullptr;
        ListNode* cur = *head;
        ListNode* post = cur->pNext;
        while (post) {
            cur->pNext = pre;
            pre = cur;
            cur = post;
            post = post->pNext;
        }
        cur->pNext = pre;
        *head = cur;
    }

    bool isPalindrome(ListNode* head) {
        if (!head || !head->pNext) {return true;}
        ListNode* fastPointer = head, *slowPointer = head, *beforeMid;
        while (fastPointer && fastPointer->pNext) {
            fastPointer = fastPointer->pNext->pNext;
            beforeMid = slowPointer;
            slowPointer = slowPointer->pNext;
        }
        beforeMid->pNext = nullptr;
        reverseList(&slowPointer);
        while (head && slowPointer) {
            if (head->val != slowPointer->val) {return false;}
            head = head->pNext;
            slowPointer = slowPointer->pNext;
        }
        return true;
    }
};