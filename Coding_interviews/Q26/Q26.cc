#include <iostream>
#include "../../DataStructure/BinaryTree.h"

class Solution {
public:
    bool Equal(int a, int b) {
        if ((a - b > -0.0000000001) && (a - b < 0.0000000001)) {return true;}
        else {return false;}
    }

    bool hasSubTree(TreeNode* root1, TreeNode* root2) {
        if (!root1 && root2) {return false;}
        if (!root2) {return true;}
        if (!Equal(root1->val, root2->val)) {return false;}
        return hasSubTree(root1->left, root2->left) 
        && hasSubTree(root1->right, root2->right);
    } 

    bool DoesTree1HasTree2(TreeNode* root1, TreeNode* root2) {
        if (!root1 && root2) {return false;}
        if (!root2) {return true;}
        return hasSubTree(root1, root2) 
        || DoesTree1HasTree2(root1->left, root2)
        || DoesTree1HasTree2(root1->right, root2);
    }
};

int main(int argc, const char** argv) {
    TreeNode* t1_8 = new TreeNode(8);
    TreeNode* t1_7 = new TreeNode(7);
    TreeNode* t1_6 = new TreeNode(6, t1_8, nullptr);
    TreeNode* t1_5 = new TreeNode(5);
    TreeNode* t1_4 = new TreeNode(1, nullptr, t1_7);
    TreeNode* t1_3 = new TreeNode(3, t1_5, t1_6); 
    TreeNode* t1_2 = new TreeNode(2, t1_4, nullptr);
    TreeNode* root1 = new TreeNode(1, t1_2, t1_3); 

    TreeNode* t2_4 = new TreeNode(1);
    TreeNode* t2_3 = new TreeNode(3); 
    TreeNode* t2_2 = new TreeNode(2, t2_4, nullptr);
    TreeNode* root2 = new TreeNode(1, t2_2, t2_3);

    Solution s;
    if (s.DoesTree1HasTree2(root1, root2)) {printf("Tree2 is a Subtree of Tree1\n");}
    else {printf("Tree2 is NOT a Subtree of Tree1\n");}
    return 0;
}