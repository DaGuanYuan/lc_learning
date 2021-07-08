#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    void findMinHeightTrees(std::vector<std::vector<int> >& graph,
                            std::vector<int>& res,
                            int& minDepth,
                            int n,
                            int operateNode) {
        std::queue<int> q;
        std::vector<bool> visited(n, false);
        q.push(operateNode);
        visited[operateNode] = true;
        int depth = 0;
        int size = 0;
        int currentNode = 0;
        while (!q.empty()) {
            ++depth;
            if (depth > minDepth) {return;}
            size = q.size();
            while (size--) {
                currentNode = q.front();
                q.pop();
                for (const int& val : graph[currentNode]) {
                    if (!visited[val]) {
                        q.push(val);
                        visited[val] = true;    
                    }
                }
            }
        }
        if (depth < minDepth) {
            res.clear();
            minDepth = depth;
        }
        res.push_back(operateNode);
    }

    std::vector<int> findMinHeightTrees(int n, std::vector<std::vector<int> >& edges) {
        if (n == 1) {return {0};}
        std::vector<std::vector<int> > graph(n);
        for (const std::vector<int>& vec : edges) {
            graph[vec[0]].push_back(vec[1]);
            graph[vec[1]].push_back(vec[0]);
        }
        int minDepth = INT32_MAX;
        std::vector<int> res;
        for (int i = 0; i < n; ++i) {
            findMinHeightTrees(graph, res, minDepth, n, i);
        }
        return res;
    }

    std::vector<int> findMinHeightTrees_Optimal(int n, std::vector<std::vector<int> >& edges) {
        if (n == 1) {return {0};}
        std::vector<int> degrees(n);
        std::vector<std::vector<int> > graph(n);
        std::vector<int> res;
        for (const std::vector<int>& vec : edges) {
            ++degrees[vec[0]];
            ++degrees[vec[1]];
            graph[vec[0]].push_back(vec[1]);
            graph[vec[1]].push_back(vec[0]);
        }
        std::queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (degrees[i] == 1) {q.push(i);}
        }
        
        int size = 0;
        int current = 0;
        while (!q.empty()) {
            res.clear();
            size = q.size();
            while (size--) {
                current = q.front();
                q.pop();
                res.push_back(current);
                for (const int& val : graph[current]) {
                    --degrees[val];
                    if (degrees[val] == 1) {q.push(val);}
                }
            }
        }
        return res;
    }   
};