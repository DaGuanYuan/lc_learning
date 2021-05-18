#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include "../../DataStructure/BinaryTree.h"

class Codec
{

public:
    std::vector<std::string> splitByDot(std::string data) {
        data = data.substr(1, data.size()-2);
        int start = 0;
        std::vector<std::string> rst{};
        while (start < data.size()) {
            int startIndex = start;
            while (startIndex < data.size() && data[startIndex] != ',') {startIndex++;}
            rst.push_back(data.substr(start, startIndex - start));
            start = startIndex + 1;
        }
        return rst;
    }

    std::string serialize_byLayer(TreeNode* root) {
        if (!root) {return "[]";}
        std::string rst{"["};
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* tempNode = q.front();
            q.pop();
            if (tempNode) {
                rst += std::to_string(tempNode->val);
                rst += ',';
                q.push(tempNode->left);
                q.push(tempNode->right);
            }
            else {rst += "null,";}
        }
        rst.pop_back();
        rst.push_back(']');
        return rst;
    }

    TreeNode* deserialize_byLayer(std::string data) {
        if (data == "[]") {return nullptr;}
        std::vector<std::string> splitVector = splitByDot(data);
        std::queue<TreeNode*> q;
        TreeNode* root = new TreeNode(atoi(splitVector[0].c_str()));
        int splitIndex = 1;
        q.push(root);
        while (!q.empty()) {
            TreeNode* tempNode = q.front();
            q.pop();
            if (splitVector[splitIndex] != "null") {
                tempNode->left = new TreeNode(atoi(splitVector[splitIndex].c_str()));
                q.push(tempNode->left);
            }
            splitIndex++;
            if (splitVector[splitIndex] != "null") {
                tempNode->right = new TreeNode(atoi(splitVector[splitIndex].c_str()));
                q.push(tempNode->right);
            }
            splitIndex++;            
        }
        return root;
    }

    std::string serialize_byDFS(TreeNode* root) {
        if (!root) {return "[]";}
        std::string res{"["};
        res.append(serialize_byDFSCore(root).c_str());
        res.pop_back();
        res.push_back(']');
        return res;
    }

    std::string serialize_byDFSCore(TreeNode* root) {
        if (!root) {return "null,";}
        std::string serialize_seq {};
        serialize_seq += std::to_string(root->val);
        serialize_seq += ',';
        serialize_seq.append(serialize_byDFSCore(root->left));
        serialize_seq.append(serialize_byDFSCore(root->right));
        return serialize_seq;
    }

    TreeNode* deserialize_byDFS(std::string data) {
        if (data == "[]") {return nullptr;}
        std::vector<std::string> splitVector = splitByDot(data);
        std::queue<std::string> splitQueue;
        for (std::string splitVal : splitVector) {splitQueue.push(splitVal);}
        TreeNode* root = deserialize_byDFSCore(splitQueue);
        return root;
    }

    TreeNode* deserialize_byDFSCore(std::queue<std::string>& splitQueue) {
        if (splitQueue.empty()) {return nullptr;}
        std::string cur = splitQueue.front();
        splitQueue.pop();
        if (cur == "null") {return nullptr;}
        TreeNode* root = new TreeNode(atoi(cur.c_str()));
        root->left = deserialize_byDFSCore(splitQueue);
        root->right = deserialize_byDFSCore(splitQueue);
        return root;
    }
};

int main(int argc, const char** argv) {
    Codec serializeClass;
    // nullptr, only root
    // only left tree && only right tree
    // normal test(complete binary tree...)
    TreeNode* t5 = new TreeNode(5);
    TreeNode* t4 = new TreeNode(4);
    TreeNode* t3 = new TreeNode(3, t4, t5);
    TreeNode* t2 = new TreeNode(2);
    TreeNode* t1 = new TreeNode(1, t2, t3);
    TreeNode* root = t1;
    std::string serialResult = serializeClass.serialize_byDFS(root);
    printf("Serializing Result:\n");
    printf("%s\n", serialResult.c_str());
    TreeNode* deserialResult = serializeClass.deserialize_byDFS(serialResult);
    return 0;
}