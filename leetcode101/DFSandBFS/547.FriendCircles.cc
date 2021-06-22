#include <iostream>
#include <vector>

class Solution {
public:
    void visitCities(std::vector<std::vector<int> >& isConnected,
                     std::vector<bool>& visited,
                     int i) {
        for (int j = 0; j < isConnected.size(); ++j) {
            if (isConnected[i][j] == 1) {visited[j] = true;}
            visitCities(isConnected, visited, j);
        }
    }

    int findCirclesNum(std::vector<std::vector<int> >& isConnected) {
        if (isConnected.empty()) {return 0;}
        int n = isConnected.size();
        int circleNum = 0;
        std::vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++circleNum;
                visitCities(isConnected, visited, i);
            }
        }
        return circleNum;
    }
};