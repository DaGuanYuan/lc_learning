#include <iostream>
#include <queue>
#include "../../DataStructure/BinaryTree.h"

class Solution {
public:
    int depthofBinaryTree_Solution1(TreeNode* root) {
        if (!root) {return 0;}
        std::queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        int layerSize = 0; //layer size
        while (!q.empty()) {
            layerSize = q.size();
            while (layerSize) {
                TreeNode* tempNode = q.front();
                q.pop();
                if (tempNode->left) {q.push(tempNode->left);}
                if (tempNode->right) {q.push(tempNode->right);}
                layerSize--;
            }
            depth++;
        }
        return depth;
    }

    int depthofBinaryTree_Solution2(TreeNode* root) {
        if (!root) {return 0;}
        return 1 + std::max(depthofBinaryTree_Solution2(root->left),
                            depthofBinaryTree_Solution2(root->right));
    }
};

int main(int argc, const char** argv) {
    Solution s;
    // !root, or only root
    // all nodes have only left child or only right child
    // normal
    TreeNode* p8 = new TreeNode(8);
    TreeNode* p6 = new TreeNode(6);
    TreeNode* p4 = new TreeNode(4);
    TreeNode* p2 = new TreeNode(2);
    TreeNode* p7 = new TreeNode(7, p6, p8);
    TreeNode* p3 = new TreeNode(3, p2, p4);
    TreeNode* p5 = new TreeNode(5, p3, p7);
    TreeNode* root = p5;
    int depth = s.depthofBinaryTree_Solution1(root);
    printf("The depth of Tree is %d\n", depth);
    return 0;
}