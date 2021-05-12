#include <iostream>
#include "../../DataStructure/BinaryTree.h"

class Solution {
public:
    TreeNode* convertBFStoDoublyLinkedList(TreeNode* root) {
        if (!root) {return nullptr;}
        TreeNode* leftList = convertBFStoDoublyLinkedList(root->left);
        TreeNode* rightList = convertBFStoDoublyLinkedList(root->right);
        TreeNode* temp = nullptr;
        if (leftList) {
            temp = leftList;
            while (temp->right) {temp = temp->right;}
            temp->right = root;
        }
        if (rightList) {rightList->left = root;}
        root->left = temp;
        root->right = rightList;
        return leftList ? leftList : root;  
    }

    TreeNode* convertBFStoDoublyLinkedList_Solution2(TreeNode* root) {
        convertBFStoDoublyLinkedList_Solution2Core(root);
        return head;
    }

private:
    TreeNode* pre = nullptr;
    TreeNode* head = nullptr;
    // This Convert Function means "Connecting root with previous list"
    // and assign pre to root which is the current function parameter
    // FOR EXAMPLE: convertBFStoDoublyLinkedList_Solution2Core(root->left)
    // means connecting root->left with its previous(not only Children!)
    // trees(value < root->left->val) and setting pre as root->left;
    void convertBFStoDoublyLinkedList_Solution2Core(TreeNode* root) {
        if (!root) {return;}
        convertBFStoDoublyLinkedList_Solution2Core(root->left);
        if (pre) {pre->right = root;}
        else {head = root;}
        root->left = pre;
        pre = root;
        convertBFStoDoublyLinkedList_Solution2Core(root->right);
    }
};

int main(int argc, const char** argv) {
    Solution s;
    // !root, only root
    // only left tree, only right tree
    // normal(Complete binary tree...)
    TreeNode* t1 = new TreeNode(1);
    TreeNode* t3 = new TreeNode(3);
    TreeNode* t2 = new TreeNode(2, t1, t3);
    TreeNode* t5 = new TreeNode(5);
    TreeNode* t4 = new TreeNode(4, t2, t5);
    TreeNode* root = t4;
    TreeNode* listHead = s.convertBFStoDoublyLinkedList(root);
    printf("Printing the list in order:\n");
    TreeNode* p = listHead;
    while (p->right) {
        printf("%d ", p->val);
        p = p->right;
    }
    printf("%d\n", p->val);
    printf("Printing the list reversely:\n");
    while (p->left) {
        printf("%d ", p->val);
        p = p->left;
    }
    printf("%d\n", p->val);
    return 0;
}