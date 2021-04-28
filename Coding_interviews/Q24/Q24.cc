#include <iostream>
#include "../../DataStructure/ListNode.h"

class Solution {
public:
    void printList(ListNode* head) {
        if (!head) {printf("The List is Empty!");}
        while (head) {
            printf("%d ", head->val);
            head = head->pNext;
        }
        printf("\n");
    }

    ListNode* reverseList(ListNode* head) {
        if (!head || !head->pNext) {return head;}
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* post = head->pNext;
        while (post) {
            cur->pNext = pre;
            pre = cur;
            cur = post;
            post = post->pNext;
        }
        cur->pNext = pre;
        return cur;
    }
};

int main(int argc, const char** argv) {
    ListNode* l6 = new ListNode(6);
    ListNode* l5 = new ListNode(5, l6);
    ListNode* l4 = new ListNode(4, l5);
    ListNode* l3 = new ListNode(3, l4);
    ListNode* l2 = new ListNode(2, l3);
    ListNode* l1 = new ListNode(1, l2);
    ListNode* head = l5;
    Solution s;
    printf("Before Reversing:\n");
    s.printList(head);
    ListNode* headAfterReversing = s.reverseList(head);
    if (headAfterReversing) {
        printf("After Reversing:\n");
        s.printList(headAfterReversing);
    }
    return 0;
}
