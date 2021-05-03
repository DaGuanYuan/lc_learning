#include <iostream>
#include <unordered_map>

class complexListNode {
public:
    complexListNode() 
    : val(0)
    , next(nullptr)
    , random(nullptr) {}

    complexListNode (int val) 
    : val(val)
    , next(nullptr)
    , random(random) {}

    complexListNode (int val, complexListNode* next) 
    : val(val)
    , next(next)
    , random(nullptr) {}

    complexListNode (int val, complexListNode* next, complexListNode* random) 
    : val(val)
    , next(next)
    , random(random) {}

    int val;
    complexListNode* next;
    complexListNode* random;
};

class Solution {
public:
    complexListNode* splitNewList(complexListNode* head) {
        complexListNode* newHead = head->next;
        complexListNode* recordNewHead = newHead;
        while (newHead && newHead->next) {
            head->next = newHead->next;
            head = newHead->next;
            newHead->next = head->next;
            newHead = head->next;
        }
        head->next = nullptr;
        return recordNewHead;
    }

    void connectRandomNodeOfNewComplexListNode(complexListNode* head) {
        complexListNode* newHead = head->next;
        while (newHead->next) {
            // PLZ REMEMBER: every time you wanna access a point, 
            // for example p->val or p->next. Please confirm p is existed!!!
            if (head->random) {newHead->random = head->random->next;}
            head = head->next->next;
            newHead = newHead->next->next;
        }
        if (head->random) {newHead->random = head->random->next;}
    }

    void cloneComplexListNodeOneByOne(complexListNode* head) {
        complexListNode* newHead;
        while (head) {
            newHead = new complexListNode(head->val);
            newHead->next = head->next;
            head->next = newHead;
            head = newHead->next;
        }        
    }

    complexListNode* cloneComplexListNode(complexListNode* head) {
        if (!head) {return nullptr;}
        cloneComplexListNodeOneByOne(head);
        connectRandomNodeOfNewComplexListNode(head);
        return splitNewList(head);
    }

    complexListNode* cloneComplexListNode_HashMethod(complexListNode* head) {
        if (!head) {return nullptr;}
        std::unordered_map<complexListNode*, complexListNode*> map;
        complexListNode* p = head;
        while (p) {
            map[p] = new complexListNode(p->val);
            p = p->next;
        }
        p = head;
        while (p) {
            map[p]->next = map[p->next];
            map[p]->random = map[p->random];
            p = p->next;
        }
        return head;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    // nullptr
    // only one node c1->random = c1
    // two node c1, c2   c1->random = c2 && c2->random = c1
    // normal
    complexListNode* c5 = new complexListNode(1);
    complexListNode* c4 = new complexListNode(10, c5);
    complexListNode* c3 = new complexListNode(11, c4, c5);
    complexListNode* c2 = new complexListNode(13, c3);
    complexListNode* c1 = new complexListNode(7, c2);
    c2->random = c1;
    c4->random = c3;
    c5->random = c1;
    complexListNode* head = c1;
    complexListNode* newHead = s.cloneComplexListNode_HashMethod(head);
    complexListNode* traverse1 = newHead;
    complexListNode* traverse2 = newHead;
    printf("Cloned Lists' Next Node:\n");
    while (traverse1) {
        printf("%d ", traverse1->val);
        traverse1 = traverse1->next;
    }
    printf("\nCloned Lists' Random Node:\n");
    while (traverse2) {
        if (traverse2->random) {printf("%d\n", traverse2->random->val);}
        traverse2 = traverse2->next;
    }
    return 0;
}