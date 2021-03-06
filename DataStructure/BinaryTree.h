#ifndef __TREENODE__
#define __TREENODE__

#include <iostream>

class TreeNode {
public:
    TreeNode() = default;

    TreeNode(int val)
    : val(val) {
        left = nullptr;
        right = nullptr;
    }
    TreeNode(int val, TreeNode* left, TreeNode* right)
    : val(val)
    , left(left)
    , right(right) {}
    TreeNode(const TreeNode&) = default;
    int val;    
    TreeNode* left;
    TreeNode* right;
};


#endif // __TREENODE__
