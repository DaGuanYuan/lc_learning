#include <iostream>
#include "../../DataStructure/BinaryTree.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {return nullptr;}
        int maxVal = std::max(p->val, q->val);
        int minVal = std::min(p->val, q->val);
        TreeNode* res = root;
        while (res) {
            if (res->val <= maxVal && res->val >= minVal) {return res;}
            else if (res->val > maxVal) {res = res->left;}
            else if (res->val < minVal) {res = res->right;}
        }
        return res;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    // !root, and only root
    // only left tree, only right tree
    // nornal(complete binary tree...)
    // p, q = root
    // p, q are on same side of the root
    // p, q are on different sides of the root 
    TreeNode* p8 = new TreeNode(8);
    TreeNode* p6 = new TreeNode(6);
    TreeNode* p4 = new TreeNode(4);
    TreeNode* p2 = new TreeNode(2);
    TreeNode* p7 = new TreeNode(7, p6, p8);
    TreeNode* p3 = new TreeNode(3, p2, p4);
    TreeNode* p5 = new TreeNode(5, p3, p7);
    TreeNode* root = p5;
    TreeNode* p = p2;
    TreeNode* q = p3;
    TreeNode* res = s.lowestCommonAncestor(root, p, q);
    printf("The lowest common ancestor of p, q is: %d\n", res->val);
    return 0;
}