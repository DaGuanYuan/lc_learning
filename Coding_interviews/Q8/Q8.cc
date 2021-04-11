#include <iostream>

class specialTree {
public:
    specialTree* left;
    specialTree* right;
    specialTree* father;
    char val;
    specialTree()
        :val('\0')
        ,left(nullptr)
        ,right(nullptr)
        ,father(nullptr) {}

    specialTree(char val)
        :val(val)
        ,left(nullptr)
        ,right(nullptr)
        ,father(nullptr) {}

    specialTree(char val, specialTree* left, specialTree* right)
        :val(val)
        ,left(left)
        ,right(right)
        ,father(nullptr) {}

    specialTree(char val, specialTree* left, specialTree* right, specialTree* father)
        :val(val)
        ,left(left)
        ,right(right)
        ,father(father) {}

    specialTree(const specialTree& lhs) {
        if (lhs.left && lhs.right && lhs.father) {
            this->left = new specialTree(*lhs.left);
            this->right = new specialTree(*lhs.right);
            this->father = new specialTree(*lhs.father);
        }
    }
    
    ~specialTree() {
        if (this->left) {
            delete this->left;
            this->left = nullptr;
        }
        if (this->right) {
            delete this->right;
            this->right = nullptr;
        }
        if (this->father) {
            delete this->father;
            this->father = nullptr;
        }
    }
};

class Solution {
public:
    specialTree* getNext(specialTree* p) {
        if (!p) {return nullptr;}
        specialTree* pNext = nullptr;
        if (p->right) {
            specialTree* pRight = p->right; //do not overload operator=
            while (pRight->left) {
                pRight = pRight->left;
            }
            pNext = pRight;
        }
        else {
            if (p == p->father->left) {pNext = p->father;}
            else {
                while (p->father && p == p->father->right) {
                    p = p->father;
                }
                pNext = p->father;
            }
        }
        return pNext;
    }
};

int main(int argc, const char** argv) {
    // specialTree *a, *b, *c, *d, *e, *f, *g, *h, *i;
    specialTree* h = new specialTree('h');
    specialTree* i = new specialTree('i');
    specialTree* d = new specialTree('d');
    specialTree* e = new specialTree('e', h, i);
    specialTree* f = new specialTree('f');
    specialTree* g = new specialTree('g');
    specialTree* b = new specialTree('b', d, e);
    specialTree* c = new specialTree('c', f, g);
    specialTree* a = new specialTree('a', b, c);
    h->father = e;
    i->father = e;
    d->father = b;
    e->father = b;
    f->father = c;
    g->father = c;
    b->father = a;
    c->father = a;
    Solution s;
    specialTree* res = s.getNext(g);
    if (res) {printf("The next node is %c\n", res->val);}
    else {printf("The next node is nullptr\n");}
    
    return 0;
}