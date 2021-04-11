#include <iostream>
#include <vector>
#include <unordered_map>
#include "../DataStucture/BinaryTree.h"

class Solution {
public:
    TreeNode* reConstructionTree(std::vector<int>& pre_order, std::vector<int>& in_order) {
        if (pre_order.empty() || in_order.empty() || in_order.size()!=pre_order.size()) {
            return nullptr;
        }
        int n = in_order.size();
        for (int i = 0; i < n; i++) {
            mp[in_order[i]] = i;
        }
        return reConstructionTree(pre_order, 0, 0, n - 1);
    }

    TreeNode* reConstructionTree(std::vector<int>& pre_order,
                                 int preIndex,
                                 int inLeft,
                                 int inRight) {
        if (inLeft < inRight) {return nullptr;}
        TreeNode* root = new TreeNode(pre_order[preIndex]); 
        int inIndex = mp[pre_order[preIndex]];
        if (inIndex < inLeft || inIndex > inRight) {printf("Invalid input.");}
        root->left = reConstructionTree(pre_order, preIndex + 1, inLeft, inIndex - 1);
        root->right = reConstructionTree(pre_order, preIndex + inIndex - inLeft + 1, inIndex + 1, inRight);
        return root;
    }

private:
    std::unordered_map<int, int> mp;
};


int main() {
    TreeNode* t8 = new TreeNode(8);
    TreeNode* t7 = new TreeNode(7);
    TreeNode* t6 = new TreeNode(6, t8, nullptr);
    TreeNode* t5 = new TreeNode(5);
    TreeNode* t4 = new TreeNode(4, nullptr, t7);
    TreeNode* t3 = new TreeNode(3, t5, t6); 
    TreeNode* t2 = new TreeNode(2, t4, nullptr);
    TreeNode* root = new TreeNode(1, t2, t3); 

    std::vector<int> pre_order{1, 2, 4, 7, 3, 5, 6, 8};
    std::vector<int> in_order{4, 7, 2, 1, 5, 3, 8, 6};
    Solution s;
    s.reConstructionTree(pre_order, in_order);
    return 0;
}