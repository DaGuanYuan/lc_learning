#include <iostream>
#include "../../DataStructure/ListNode.h"

class Solution {
public:
    void printList(ListNode* head) {
        if (!head) {printf("This List is Empty!");}
        while (head) {
            printf("%d ", head->val);
            head = head->pNext;
        }
        printf("\n");

    }
    ListNode* mergeTwoSortedLists_Soluton1(ListNode* head1, ListNode* head2) {
        if (!head1 && !head2) {return nullptr;}
        ListNode* preHead = new ListNode(-INT32_MAX);
        ListNode* pre = preHead;
        while (head1 && head2) {
            if (head1->val <= head2->val) {
                pre->pNext = head1;
                head1 = head1->pNext;
            }
            else {
                pre->pNext = head2;
                head2 = head2->pNext;
            }
            pre = pre->pNext;   //pre always refers to the first node in UNSORTED lists
        }
        pre->pNext = head1 ? head1 : head2;
        return preHead->pNext;
    }
    ListNode* mergeTwoSortedLists_Soluton2(ListNode* head1, ListNode* head2) {
        if (!head1) {return head2;}
        if (!head2) {return head1;}
        ListNode* pHead;
        if (head1->val <= head2->val) {
            pHead = head1;
            pHead->pNext = mergeTwoSortedLists_Soluton2(head1->pNext, head2);
        }
        else {
            pHead = head2;
            pHead->pNext = mergeTwoSortedLists_Soluton2(head1, head2->pNext);
        }
        return pHead;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    ListNode* l1_7 = new ListNode(7);
    ListNode* l1_6 = new ListNode(6, l1_7);
    ListNode* l1_5 = new ListNode(5, l1_6);
    ListNode* l1_4 = new ListNode(4, l1_5);
    ListNode* l1_3 = new ListNode(3, l1_4);
    ListNode* l1_2 = new ListNode(2, l1_3);
    ListNode* l1_1 = new ListNode(1, l1_2);
    ListNode* head1 = l1_1;
    printf("Head1: ");
    s.printList(head1);

    ListNode* l2_4 = new ListNode(6);
    ListNode* l2_3 = new ListNode(5, l2_4);
    ListNode* l2_2 = new ListNode(3, l2_3);
    ListNode* l2_1 = new ListNode(1, l2_2);   
    ListNode* head2 = l2_1;
    printf("Head2: ");
    s.printList(head2);

    ListNode* afterMerging = s.mergeTwoSortedLists_Soluton2(head1, head2);
    printf("AfterMerging: ");
    s.printList(afterMerging);
    return 0;
}