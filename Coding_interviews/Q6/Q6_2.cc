#include <iostream>
#include "../DataStucture/LinkNode.h"

void AddtoTail(LinkNode** pHead, int value) {
    LinkNode* pNew = new LinkNode(value);
    if (pHead == nullptr) {*pHead = pNew;}
    LinkNode* pNode = *pHead;
    while (pNode->pNext != nullptr) {
        pNode = pNode->pNext;
    } 
    pNode->pNext = pNew;
}

//pHead == nullptr indicates that the list is not existed
//*pHead == nullptr illuminates that the list is empty
void AddtoList(LinkNode** pHead, int pos, int value) {
    LinkNode* pNew = new LinkNode(value);
    if (pos <= 0 || pHead == nullptr || (pos > 1 && *pHead == nullptr)) {
        printf("Error");
        return;
    }
    if (pos == 1) {
        pNew->pNext = (*pHead)->pNext;
        (*pHead) = pNew;
    }
    LinkNode* pNode = *pHead;
    while (pNode->pNext!= nullptr && pos!=2) {
        pNode = pNode->pNext;
        --pos;
    }
    if (pNode->pNext == nullptr && pos > 2) {
        printf("Error, Out of range!");
        return;
    }
    pNew = pNode->pNext;
    pNode->pNext = pNew;
}

void RemovefromList(LinkNode** pHead, int pos) {
    if (pos <= 0 || pHead == nullptr || (pos > 1 && *pHead == nullptr)) {
        printf("Error");
        return;
    }
    LinkNode* p = *pHead;
    if (pos == 1) {
        (*pHead) = (*pHead)->pNext;
        delete(p);
    }
    LinkNode* pNode = *pHead;
    while (pNode->pNext != nullptr && pos != 2) {
        pNode = pNode->pNext;
        pos--;
    }
    if (pNode->pNext == nullptr && pos > 2) {
        printf("Error, Out of range!");
        return;
    }
    p = pNode->pNext;
    pNode = p->pNext;
    delete(p);
}
