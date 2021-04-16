#ifndef __LISTNODE__
#define __LISTNODE__

#include <iostream>
class ListNode {
public:
    ListNode() = default;
    ListNode(int val) 
    : val(val) {
        pNext = nullptr;
    }
    ListNode(int val, ListNode* pNext) 
    : val(val)
    , pNext(pNext) {}

    ListNode(const ListNode&) = default;
public:
    ListNode* pNext;
    int val;
};

#endif // __LISTNODE__