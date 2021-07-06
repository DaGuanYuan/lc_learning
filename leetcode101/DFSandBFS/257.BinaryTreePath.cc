#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include "../../DataStructure/BinaryTree.h"

class Solution {
public:
    void binaryTreePath(TreeNode* root, std::vector<std::vector<int> >& res, std::vector<int>& temp) {
        if (!root) {return;}
        temp.push_back(root->val);
        if (!root->left && !root->right) {
            res.push_back(temp);
        }   
        binaryTreePath(root->left, res, temp);
        binaryTreePath(root->right, res, temp);
        temp.pop_back();    
    }

    std::vector<std::string> binaryTreePath(TreeNode* root) {
        if (!root) {return {};}
        std::vector<std::vector<int> > res;
        std::vector<int> temp{};
        binaryTreePath(root, res, temp);
        std::vector<std::string> ans;
        std::string str{""};
        for (std::vector<int> path : res) {
            for (int node : path) {
                str += std::to_string(node);
                str += "->";
            }
            str.pop_back();
            str.pop_back();
            ans.push_back(str);
            str.clear();
        }
        return ans;
    }

    std::vector<std::string> binaryTreePaths(TreeNode* root) {
        if (!root) {return {};}
        std::queue<TreeNode*> qNode;
        std::queue<std::string> qStr;
        std::vector<std::string> res;
        qNode.push(root);
        std::string temp{""};
        temp += std::to_string(root->val) + "->";
        qStr.push(temp);
        while (!qNode.empty()) {
            TreeNode* thisLayer = qNode.front();
            temp = qStr.front();
            qNode.pop();
            qStr.pop();
            if (!thisLayer->left && !thisLayer->right) {
                temp.pop_back();
                temp.pop_back();
                res.push_back(temp);
            }
            if (thisLayer->left) {
                qNode.push(thisLayer->left);
                qStr.push(temp+std::to_string(thisLayer->left->val)+"->");
            }
            if (thisLayer->right) {
                qNode.push(thisLayer->right);
                qStr.push(temp+std::to_string(thisLayer->right->val)+"->");
            }
        }
        return res;
    }
};