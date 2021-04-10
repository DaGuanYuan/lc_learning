#include "iostream"
#include "vector"
#include "map"
using _value = int32_t;

class TreeNode {
public:
    TreeNode() = default;

    TreeNode(int value)
    : value(value) {
        left = nullptr;
        right = nullptr;
    }
    TreeNode(int value, TreeNode* left, TreeNode* right)
    : value(value)
    , left(left)
    , right(right) {}
    TreeNode(const TreeNode&) = default;
    int32_t value;    
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:
    TreeNode* ReconstructionTree(std::vector<int>& pre_order, std::vector<int>& in_order, int length) {
        if (pre_order.empty() || in_order.empty() || in_order.size()!=pre_order.size() || length <= 0) {
            return nullptr;
        }
    }

    TreeNode* ReconstructionTree(std::vector<int>& pre_order,
                                 std::vector<int>&in_order,
                                 int length,
                                 int startPreorder,
                                 int endPreorder,
                                 int startInorder,
                                 int endInorder) {
        if (pre_order.empty() || in_order.empty() || length<=0 || in_order.size()!=pre_order.size()) {
            return nullptr;
        }
        
    }

    int indexInOrder(int val, std::vector<int>& in_order) {
        
    }
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
    int length = pre_order.size();
    return 0;
}