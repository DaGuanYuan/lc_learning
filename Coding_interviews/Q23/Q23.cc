#include <iostream>
#include "../../DataStructure/ListNode.h"

class Solution {
public:
    ListNode* meetingNode(ListNode* head) {
        if (!head) {return nullptr;}
        ListNode* fastPoint = head;
        ListNode* slowPoint = head;
        while (fastPoint && fastPoint->pNext) {
            fastPoint = fastPoint->pNext->pNext;
            slowPoint = slowPoint->pNext;
            if (slowPoint == fastPoint) {return slowPoint;}
        }
        return nullptr;
    }

    int loopLength(ListNode* head) {
        ListNode* mNode = meetingNode(head);
        if (!head || !mNode) {return 0;}
        ListNode* p = mNode->pNext;
        int lengthofLoop = 1;
        while (p != mNode) {
            p = p->pNext;
            lengthofLoop++;
        }
        return lengthofLoop;
    }

    ListNode* entryNodeofLoop(ListNode* head) {
        int lengthofLoop = loopLength(head);
        if (!head || !lengthofLoop) {
            printf("No Loop in the List\n");
            return nullptr;
        }
        ListNode* firstPoint = head;
        ListNode* secondPoint = head;
        while (lengthofLoop) {
            firstPoint = firstPoint->pNext;
            lengthofLoop--;
        }
        while (firstPoint != secondPoint) {
            firstPoint = firstPoint->pNext;
            secondPoint = secondPoint->pNext;
        }
        return firstPoint;
    }
};

int main(int argc, const char** argv) {
    ListNode* l6 = new ListNode(6);
    ListNode* l5 = new ListNode(5, l6);
    ListNode* l4 = new ListNode(4, l5);
    ListNode* l3 = new ListNode(3, l4);
    ListNode* l2 = new ListNode(2, l3);
    ListNode* l1 = new ListNode(1, l2);
    l6->pNext = l3;
    ListNode* head = l1;
    Solution s;
    ListNode* entry = s.entryNodeofLoop(head);
    if (entry) {printf("%d\n", entry->val);}
    return 0;
}