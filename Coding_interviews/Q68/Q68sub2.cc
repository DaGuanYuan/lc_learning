#include <iostream>
#include "../../DataStructure/BinaryTree.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root|| root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(!left) return right;
        if(!right) return left;
        return root;
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