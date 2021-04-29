#include <iostream>
#include <vector>
#include <queue>
#include "../../DataStructure/BinaryTree.h"

class Solution {
public:
    void printBinaryTreeByLayer(TreeNode* root) {
        if (!root) {
            printf("Empty Tree! Please check your input\n");
            return;
        }
        std::vector<std::vector<int> > matrixBFS = searchBinaryTreeByLayer(root);
        for (std::vector<std::vector<int> >::iterator it1 = matrixBFS.begin(); it1 != matrixBFS.end(); it1++) {
            printf("[");
            for (std::vector<int>::iterator it2 = it1->begin(); it2 != it1->end(); it2++) {
                printf("%d ", *it2);
            }
            printf("]\n");
        }
    }

    std::vector<std::vector<int> > searchBinaryTreeByLayer(TreeNode* root) {
        std::vector<std::vector<int> > rst{};
        if (!root) {return rst;}
        std::vector<int> temp;
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int qSize = q.size();
            while (qSize) {
                TreeNode* tmpNode = q.front();
                q.pop();
                temp.push_back(tmpNode->val);
                if (tmpNode->left) {q.push(tmpNode->left);}
                if (tmpNode->right) {q.push(tmpNode->right);}
                qSize--;
            }
            rst.push_back(temp);
            temp.clear();
        }
        return rst;
    }

    void mirrorRecursively(TreeNode* root) {
        if (!root) {return;}
        if (!root->left && !root->right) {return;}
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        mirrorRecursively(root->left);
        mirrorRecursively(root->right);
    }
};

int main(int argc, const char** argv) {
    Solution s;
    TreeNode* t7 = new TreeNode(7);
    TreeNode* t6 = new TreeNode(6);
    TreeNode* t5 = new TreeNode(5);
    TreeNode* t4 = new TreeNode(4);
    TreeNode* t3 = new TreeNode(3, t6, t7);
    TreeNode* t2 = new TreeNode(2, t4, t5);
    TreeNode* t1 = new TreeNode(1, t2, t3);
    TreeNode* root = t1;
    printf("Before Mirroring:\n");
    s.printBinaryTreeByLayer(root);
    s.mirrorRecursively(root);
    printf("After Mirroring:\n");
    s.printBinaryTreeByLayer(root);
    return 0;
}