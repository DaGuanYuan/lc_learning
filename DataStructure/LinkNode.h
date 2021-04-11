#ifndef LINKNODE
#define LINKNODE

#include <iostream>
class LinkNode {
public:
    LinkNode() = default;
    LinkNode(int val) 
    : val(val) {
        pNext = nullptr;
    }
    LinkNode(int val, LinkNode* pNext) 
    : val(val)
    , pNext(pNext) {}

    LinkNode(const LinkNode&) = default;
public:
    LinkNode* pNext;
    int val;
};

#endif // !LINKNODE