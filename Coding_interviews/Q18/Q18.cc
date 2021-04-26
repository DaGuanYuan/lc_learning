#include <iostream>
#include "../../DataStructure/ListNode.h"

class Solution {
public:
    void printList(ListNode* pHead) {
        if (!pHead) {printf("nullptr");}
        while (pHead) {
            printf("%d ", pHead->val);
            pHead = pHead->pNext;
        }
        printf("\n");
    }

    void deleteNode(ListNode** head, ListNode* pToBeDeleted) {
        if (!head || !(*head)||!pToBeDeleted) {
            printf("Invalid Input");
            return;
        }
        if (pToBeDeleted->pNext == nullptr) {
            if (*head == pToBeDeleted) {
                delete pToBeDeleted;
                pToBeDeleted = nullptr;
                *head = nullptr;
            }
            else {
                ListNode* pHead = *head;
                while (pHead->pNext != pToBeDeleted) {
                    pHead = pHead->pNext;
                }
                delete pToBeDeleted;
                pHead->pNext = nullptr;
                pToBeDeleted = nullptr;
            }
        }
        else {
            ListNode* nextNode = pToBeDeleted->pNext;
            pToBeDeleted->pNext = nextNode->pNext;
            pToBeDeleted->val = nextNode->val;
            delete nextNode;
            nextNode = nullptr;
        }
    }

    void deleteDuplication(ListNode** head) {
        if (!(*head) || !head) {
            printf("Invalid Input");
            return;
        }
        while ((*head) && (*head)->pNext) {
            int tmpVal = (*head)->val;
            ListNode* tmpNode = *head;
            bool flag = false;
            while ((*head)->pNext && (*head)->pNext->val == tmpVal) {
                tmpNode = (*head)->pNext;
                delete (*head);
                *head = tmpNode;
                flag = true;
            }
            if ((*head)->val == tmpVal && flag) {
                tmpNode = (*head)->pNext;
                delete (*head);
                *head = tmpNode;
            }
            if (!flag) {break;}
        }
        ListNode* preHead = new ListNode(-1);
        preHead->pNext = *head;
        ListNode* pHead = *head;
        // if pHead == nullptr, break
        while (pHead && pHead->pNext) {
            int tmpVal = pHead->val;
            ListNode* tmpNode = pHead;
            bool flag = false;
            while (pHead->pNext && pHead->pNext->val == tmpVal) {
                tmpNode = pHead->pNext;
                delete pHead;
                pHead = tmpNode;
                flag = true;
            }
            if (pHead->val == tmpVal && flag) {
                tmpNode = pHead->pNext;
                delete pHead;
                pHead = tmpNode;
                preHead->pNext = pHead;
            }
            else if (pHead->val == tmpVal && !flag) {
                preHead = pHead;
                pHead = pHead->pNext;
                }
            else {continue;}
        }
    }

    void deleteDuplication_solution2(ListNode** head) {
        if (!(*head) || !head) {
            printf("Invalid Input");
            return;
        }
        ListNode* preHead = nullptr;
        ListNode* pHead = *head;
        while (pHead) {
            bool needToBeDeleted = false;
            if (pHead->pNext && pHead->pNext->val == pHead->val) {needToBeDeleted = true;}
            if (!needToBeDeleted) {
                preHead = pHead;
                pHead = pHead->pNext;
            }
            else {
                int tmpVal = pHead->val;
                ListNode* tmpNode = pHead;
                while (pHead && pHead->val == tmpVal) {
                    tmpNode = pHead->pNext;
                    delete pHead;
                    pHead = tmpNode;
                }
                if (!preHead) {
                    *head = pHead;
                }
                else {
                    preHead->pNext = pHead;
                }
            }
        }
    }
};

int main(int argc, const char** argv) {
    ListNode* p5 = new ListNode(4);
    ListNode* p4 = new ListNode(3, p5);
    ListNode* p3 = new ListNode(3, p4);
    ListNode* p2 = new ListNode(2, p3);
    ListNode* p1c = new ListNode(2, p2);
    ListNode* p1b = new ListNode(2, p1c);
    ListNode* p1a = new ListNode(2, p1b);
    ListNode* pHead = p1a;
    ListNode* pToBeDeleted = p5;
    Solution s;
    // s.deleteNode(&pHead, pToBeDeleted);
    s.deleteDuplication_solution2(&pHead);
    s.printList(pHead);
    return 0;
}