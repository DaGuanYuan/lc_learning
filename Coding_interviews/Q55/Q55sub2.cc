#include <iostream>
#include "../../DataStructure/BinaryTree.h"

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) {return true;}
        return isBalancedCore(root) != -1;
    }

    int isBalancedCore(TreeNode* root) {
        if (!root) {return 0;}
        int left = isBalancedCore(root->left);
        if (left == -1) {return -1;}
        int right = isBalancedCore(root->right);
        if (right == -1) {return -1;}
        return std::abs(left - right) < 2 ? std::max(left, right) + 1 : -1;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    // !root, only root, and only root with a left child or right child
    // isBalanced Tree/ is not balaced tree, all nodes have no left/right children included
    TreeNode* p8 = new TreeNode(8);
    TreeNode* p6 = new TreeNode(6);
    TreeNode* p4 = new TreeNode(4);
    TreeNode* p2 = new TreeNode(2);
    TreeNode* p7 = new TreeNode(7, p6, p8);
    TreeNode* p3 = new TreeNode(3, p2, p4);
    TreeNode* p5 = new TreeNode(5, p3, p7);
    TreeNode* root = p5;
    bool isBalanced = s.isBalanced(root);
    if (isBalanced) {printf("This tree is a balanced tree\n");}
    else {printf("This tree is not a balanced tree\n");}
    return 0;
} 