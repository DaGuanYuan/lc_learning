#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int> > updateMatrix(std::vector<std::vector<int> >& mat) {
        if (mat.empty()) {return {};}
        int row = mat.size();
        int column = mat[0].size();
        std::vector<std::vector<int> > distance(row, std::vector<int>(column, INT32_MAX - 1));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (mat[i][j] == 1) {
                    if (i > 0) {distance[i][j] = std::min(distance[i - 1][j] + 1, distance[i][j]);}
                    if (j > 0) {distance[i][j] = std::min(distance[i][j - 1] + 1, distance[i][j]);}
                } else {
                    distance[i][j] = 0;
                }
            }
        }
        
        for (int i = row - 1; i >= 0; --i) {
            for (int j = column - 1; j >= 0; --j) {
                if (mat[i][j] == 1) {
                    if (i < row - 1) {distance[i][j] = std::min(distance[i + 1][j] + 1, distance[i][j]);}
                    if (j < column - 1) {distance[i][j] = std::min(distance[i][j + 1] + 1, distance[i][j]);}
                }
            }
        }
        return distance;
    }
};