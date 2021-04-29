#include <iostream>
#include "../../DataStructure/BinaryTree.h"

class Solution {
public:
    bool isTwoTreeSymmetrical(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) {return true;}
        else if (!root1 || !root2) {return false;}
        if (root1->val == root2->val) {
            return isTwoTreeSymmetrical(root1->left, root2->right)
            && isTwoTreeSymmetrical(root1->right, root2->left);
        }
        return false;
    }

    bool isSymmetrical(TreeNode* root) {
        if (!root) {return true;}
        return isTwoTreeSymmetrical(root->left, root->right);
    }
};

int main(int argc, const char** argv) {
    TreeNode* t7 = new TreeNode(5);
    TreeNode* t6 = new TreeNode(7);
    TreeNode* t5 = new TreeNode(7);
    TreeNode* t4 = new TreeNode(5);
    TreeNode* t3 = new TreeNode(6, t6, t7);
    TreeNode* t2 = new TreeNode(6, t4, t5);
    TreeNode* t1 = new TreeNode(8, t2, t3);
    TreeNode* head = t1;

    Solution s;
    if (s.isSymmetrical(head)) {printf("Symmetrical!\n");}
    else {printf("NOT Symmetrical\n");}
    return 0;
}