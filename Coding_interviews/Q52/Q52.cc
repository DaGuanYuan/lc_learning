#include <iostream>
#include <stack>
#include "../../DataStructure/ListNode.h"

class Solution {
public:
    ListNode* commonNodeofTwoIntersectionList_Solution1(ListNode* l1, ListNode* l2) {
        if (!l1 || !l2) {return nullptr;}
        ListNode* pHead1 = l1;
        ListNode* pHead2 = l2;

        while (pHead1 && pHead2) {
            pHead1 = pHead1->pNext;
            pHead2 = pHead2->pNext;
        }
        pHead1 = pHead1 ? pHead1 : l2;
        pHead2 = pHead2 ? pHead2 : l1;

        while (pHead1 && pHead2) {
            pHead1 = pHead1->pNext;
            pHead2 = pHead2->pNext;
        }
        pHead1 = pHead1 ? pHead1 : l2;
        pHead2 = pHead2 ? pHead2 : l1;

        while (1) {
            if (pHead1 == pHead2) {return pHead1;}
            if (!pHead1 || !pHead2) {return nullptr;}
            pHead1 = pHead1->pNext;
            pHead2 = pHead2->pNext;
        }
        
        return nullptr;
    }

    ListNode* commonNodeofTwoIntersectionList_Solution2(ListNode* l1, ListNode* l2) {
        if (!l1 || !l2) {return nullptr;}
        std::stack<ListNode*> stk1;
        std::stack<ListNode*> stk2;
        ListNode* pHead1 = l1;
        ListNode* pHead2 = l2;
        // Emplace into stacks, where l1->stack1, l2->stack2
        while (pHead1) {
            stk1.push(pHead1);
            pHead1 = pHead1->pNext;
        }
        while (pHead2) {
            stk2.push(pHead2);
            pHead2 = pHead2->pNext;
        }
        // compare elements on the top of stacks
        ListNode* commonNode = nullptr;
        while (!stk1.empty() && !stk2.empty()) {
            if (stk1.top() != stk2.top()) {break;}
            commonNode = stk1.top();
            stk1.pop();
            stk2.pop();
        }
        return commonNode;
    }

    int getListLength(ListNode* l) {
        int length = 0;
        while (l) {
            l = l->pNext;
            length++;
        }
        return length;
    }

    ListNode* commonNodeofTwoIntersectionList_Solution3(ListNode* l1, ListNode* l2) {
        if (!l1 || !l2) {return nullptr;}
        int lengthofl1 = getListLength(l1);
        int lengthofl2 = getListLength(l2);
        int lenDiff = lengthofl2 - lengthofl1;
        ListNode* commonNode = nullptr;
        ListNode* pLongerList = l2;
        ListNode* pShortList = l1;
        if (lenDiff < 0) {
            pLongerList = l1;
            pShortList = l2;
            lenDiff = -lenDiff;
        }
        while (lenDiff) {
            lenDiff--;
            pLongerList = pLongerList->pNext;
        }
        while (1) {
            if (pLongerList == pShortList) {
                commonNode = pLongerList;
                break;
            }
            if (!pLongerList || !pShortList) {break;}
            pLongerList = pLongerList->pNext;
            pShortList = pShortList->pNext;
        }
        return commonNode;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    // one of lists is nullptr;
    // only one node
    // l1 covers l2
    // normal(the first common are in the begin/mid/end of the lists)
    // have no intersections
    ListNode* lcommon_b = new ListNode(7);
    ListNode* lcommon_a = new ListNode(6, lcommon_b);
    ListNode* l1_c = new ListNode(3, lcommon_a);
    ListNode* l1_b = new ListNode(2, l1_c);
    ListNode* l1_a = new ListNode(1, l1_b);
    ListNode* l2_b = new ListNode(4, lcommon_a);
    ListNode* l2_a = new ListNode(5, l2_b);

    ListNode* l1 = nullptr;
    ListNode* l2 = lcommon_a;
    ListNode* intersectionNode = s.commonNodeofTwoIntersectionList_Solution3(l1, l2);
    if (intersectionNode) {printf("The first common node's value is: %d\n", intersectionNode->val);}
    else {printf("Two lists have no intersections\n");}
    return 0;
}