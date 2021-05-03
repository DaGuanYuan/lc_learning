#include <iostream>
#include <vector>
#include "../../DataStructure/BinaryTree.h"

class Solution {
public:
    void findPath(TreeNode* root, int expNum) {
        // This Question is somewhat similar to Q12 
        // Plz REMEMBER: BackTracking + Pruning is one of the best 
        // solution in "find a path" Question
        if (!root) {return;}
        expNum -= root->val;
        tmp.push_back(root->val);
        if (!root->left && !root->right && expNum == 0) {
            hasNoPath = false;
            printf("[");
            for (const int val : tmp) {
                printf("%d ", val);
            }
            printf("]\n");
        }
        // How to understand "pop_back()" only once
        // The key is: standing on a normal(middle) node, rather than the top or the leaves
        // Its left and right tree has all been traversed. Ok, lets back to top nodes
        // So we should pop_back to back to father nodes
        findPath(root->left, expNum);
        findPath(root->right, expNum);
        tmp.pop_back();
    }

    std::vector<int> tmp;
    bool hasNoPath = true;
};

int main(int argc, const char** argv) {
    // nullptr
    // only left tree
    // only right tree
    // only root
    // has path(nodes' vals > < = 0), 
    // has path (added = expNum but not till leaves)
    // has over 1 pathes
    // does not have path
    Solution s;
    TreeNode* t10 = new TreeNode(1);
    TreeNode* t9 = new TreeNode(5);
    TreeNode* t8 = new TreeNode(2);
    TreeNode* t7 = new TreeNode(7);
    TreeNode* t6 = new TreeNode(4, t9, t10);
    TreeNode* t5 = new TreeNode(13);
    TreeNode* t4 = new TreeNode(11, t7, t8);
    TreeNode* t3 = new TreeNode(8, t5, t6);
    TreeNode* t2 = new TreeNode(4, t4, nullptr);
    TreeNode* t1 = new TreeNode(5, t2, t3);
    TreeNode* root = t1;
    int expNum = 22;
    printf("Path:\n");
    s.findPath(root, expNum);
    if (s.hasNoPath) {printf("Cannot Find Pathes Meeting the Requirements\n");}
    return 0;
}