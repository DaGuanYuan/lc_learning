#include <iostream>
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
        std::queue<TreeNode*> queueTreeNode;
        queueTreeNode.push(root);
        printf("Print From Top to Bottom:\n");
        while (!queueTreeNode.empty()) {
            TreeNode* tmp = queueTreeNode.front();
            queueTreeNode.pop();    
            printf("%d ", tmp->val);
            if (tmp->left) {queueTreeNode.push(tmp->left);}
            if (tmp->right) {queueTreeNode.push(tmp->right);}
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
        int toBePrinted = 1;
        int nextPrinted = 0;
        printf("Print From Top to Bottom in Lines\n");
        while (!queueTreeNode.empty()) {
            TreeNode* tmp = queueTreeNode.front();
            queueTreeNode.pop();
            printf("%d ", tmp->val);
            toBePrinted--;
            if (tmp->left) {
                queueTreeNode.push(tmp->left);
                nextPrinted++;    
            }
            if (tmp->right) {
                queueTreeNode.push(tmp->right);
                nextPrinted++;
            }
            if (!toBePrinted) {
                printf("\n");
                toBePrinted = nextPrinted;
                nextPrinted = 0;
            }
            
        }
    }

    void printFromToptoBottombyShapeZ(TreeNode* root) {
        if (!root) {
            printf("Tree is Empty!");
            return;
        }
        std::stack<TreeNode*> stk1;
        std::stack<TreeNode*> stk2;
        stk1.push(root);
        printf("Print From Top to Bottom by Shape Z\n");
        while (!stk1.empty() || !stk2.empty()) {
            TreeNode* tmp;
            while (!stk1.empty()) {
                tmp = stk1.top();
                stk1.pop();
                printf("%d ", tmp->val);
                if (tmp->left) {stk2.push(tmp->left);}
                if (tmp->right) {stk2.push(tmp->right);}
            }
            printf("\n");
            if (!stk2.empty()) {
                while (!stk2.empty()) {
                    tmp = stk2.top();
                    stk2.pop();
                    printf("%d ", tmp->val);
                    if (tmp->right) {stk1.push(tmp->right);}
                    if (tmp->left) {stk1.push(tmp->left);}
                }
                printf("\n");
            }
        }
    }
};

int main(int argc, const char** argv) {
    Solution s;
    // nullptr
    // only left tree
    // only right tree
    // only root
    // normal
    // lines == 1 (mod 2)
    // lines == 0 (mod 2)
    TreeNode* t7 = new TreeNode(7);
    TreeNode* t6 = new TreeNode(6);
    TreeNode* t5 = new TreeNode(5);
    TreeNode* t4 = new TreeNode(4);
    TreeNode* t3 = new TreeNode(3, t6, t7);
    TreeNode* t2 = new TreeNode(2, t4, t5);
    TreeNode* t1 = new TreeNode(1, t2, t3);
    TreeNode* root = t1;
    s.printFromToptoBottom(root);
    s.printFromToptoBottominLines(root);
    s.printFromToptoBottombyShapeZ(root);
    return 0;
}