#include <iostream>
#include <deque>
#include <queue>
#include <stack>
#include "../../DataStructure/BinaryTree.h"

class Solution
{
public:
    void printFromToptoBottom(TreeNode* root) {
        if (!root) {
            printf("Tree is Empty!");
            return;
        }
        std::deque<TreeNode*> dequeTreeNode;
        dequeTreeNode.push_back(root);
        printf("Print From Top to Bottom:\n");
        while (!dequeTreeNode.empty()) {
            TreeNode* tmp = dequeTreeNode.front();
            dequeTreeNode.pop_front();
            printf("%d ", tmp->val);
            if (tmp->left) {dequeTreeNode.push_back(tmp->left);}
            if (tmp->right) {dequeTreeNode.push_back(tmp->right);}
        }
        printf("\n");
    }

    void printFromToptoBottominLines(TreeNode* root) {
        if (!root) {
            printf("Tree is Empty!");
            return;
        }
        std::queue<TreeNode*> queueTreeNode;
        queueTreeNode.push(root);
        while (!queueTreeNode.empty()) {
            int qSize = queueTreeNode.size();
            while (qSize) {
                TreeNode* tmp = queueTreeNode.front();
                queueTreeNode.pop();
                printf("%d ", tmp->val);
                if (tmp->left) {queueTreeNode.push(tmp->left);}
                if (tmp->right) {queueTreeNode.push(tmp->right);}
                qSize--;
            }
            printf("\n");
        }
    }

    void printFromToptoBottombyShapeZ(TreeNode* root) {
        if (!root) {
            printf("Tree is Empty!");
            return;
        }
    }
};