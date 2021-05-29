#include <iostream>
#include <vector>
#include "../../DataStructure/BinaryTree.h"

class Solution {
public:
    TreeNode* findKthNodeinBST(TreeNode* root, int k) {
        if (!root || k <= 0) {return nullptr;}
        dfs(root, k);
        return res;
    }

private:
    void dfs(TreeNode* root, int& k) {
        if (!root || k <= 0) {return;}
        dfs(root->right, k);
        if (k-- == 1) {
            res = root;
            return;
        }
        dfs(root->left, k);
    }

    TreeNode* res;
};

int main(int argc, const char** argv) {
    Solution s;
    // !root, and only root
    // only left tree, only right tree
    // nornal(complete binary tree...)
    // k <= 0, k = 1
    // k >= tree.size()
    TreeNode* p8 = new TreeNode(8);
    TreeNode* p6 = new TreeNode(6);
    TreeNode* p4 = new TreeNode(4);
    TreeNode* p2 = new TreeNode(2);
    TreeNode* p7 = new TreeNode(7, p6, p8);
    TreeNode* p3 = new TreeNode(3, p2, p4);
    TreeNode* p5 = new TreeNode(5, p3, p7);
    TreeNode* root = p5;
    int k = 1;
    TreeNode* res = s.findKthNodeinBST(root, k);
    if (!res) {printf("Error, please check your input\n");}
    else {printf("The top %d node in the Tree is %d\n", k, res->val);}
    return 0;
}