#include <iostream>
#include <vector>
#include "../../DataStructure/ListNode.h"

class Solution {
public:
    ListNode* mergeTwoSortedList(ListNode* l1, ListNode* l2) {
        ListNode* preNode = new ListNode(INT32_MAX);
        ListNode* pre = preNode;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                pre->pNext = l1;
                l1 = l1->pNext;
            } else {
                pre->pNext = l2;
                l2 = l2->pNext;
            }
            pre = pre->pNext;
        }
        pre->pNext = l1 ? l1 : l2;
        return preNode->pNext;
    }

    ListNode* mergeKLists(std::vector<ListNode*>& lists,
                          int begin,
                          int end) {
        if (begin > end) {return nullptr;}
        if (begin == end) {return lists[begin];}
        int mid = begin + ((end - begin) >> 1);
        return mergeTwoSortedList(mergeKLists(lists, begin, mid),
                                  mergeKLists(lists, mid + 1, end));
    }

    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if (lists.empty()) {return nullptr;}
        ListNode* res = mergeKLists(lists, 0, lists.size() - 1);
        return res;
    }
};