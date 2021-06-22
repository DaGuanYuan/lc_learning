#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> directions{-1, 0, 1, 0, -1};

    void setArrive(std::vector<std::vector<int> >& heights,
                   std::vector<std::vector<bool> >& canArrive,
                   int row,
                   int column) {
        canArrive[row][column] = true;
        int x, y;
        for (int i = 0; i < 4; ++i) {
            x = row + directions[i];
            y = column + directions[i + 1];
            if (x >= 0 && x < heights.size() &&
                y >= 0 && y < heights[0].size() &&
                !canArrive[x][y] &&
                heights[x][y] >= heights[row][column]) {
                setArrive(heights, canArrive, x, y);
            }
        }
    }

    std::vector<std::vector<int> > pacificAtlantic(std::vector<std::vector<int> >& heights) {
        if (heights.empty()) {return {};}
        std::vector<std::vector<int> > res;
        int row = heights.size();
        int column = heights[0].size();
        std::vector<std::vector<bool> > canArrivePacific(row, std::vector<bool>(column, false));
        std::vector<std::vector<bool> > canArriveAtlantic(row, std::vector<bool>(column, false));
        for (int i = 0; i < row; ++i) {
            setArrive(heights, canArrivePacific, i, 0);
            setArrive(heights, canArriveAtlantic, i, column - 1);
        }

        for (int j = 0; j < column; ++j) {
            setArrive(heights, canArrivePacific, 0, j);
            setArrive(heights, canArriveAtlantic, row - 1, j);
        }

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (canArriveAtlantic[i][j] && canArrivePacific[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};