#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> directions{1,0,-1,0,1};

    int countAreaofIsland_Method1(std::vector<std::vector<int> >& grid,
                                  std::vector<std::vector<bool> >& visited,
                                  int row,
                                  int column) {
        if (row >= grid.size() || row < 0 || 
            column >= grid[0].size() || column < 0 ||
            visited[row][column] || !grid[row][column]) {return 0;}
        visited[row][column] = true;
        return 1 + countAreaofIsland_Method1(grid, visited, row - 1, column)
                 + countAreaofIsland_Method1(grid, visited, row + 1, column)
                 + countAreaofIsland_Method1(grid, visited, row, column + 1)
                 + countAreaofIsland_Method1(grid, visited, row, column - 1); 
    }

    int countAreaofIsland_Method2(std::vector<std::vector<int> >& grid,
                                  std::vector<std::vector<bool> >& visited,
                                  int row,
                                  int column) {
        if (!grid[row][column]) {return 0;}
        int x,y,areaofIsland = 0;
        for (int i = 0; i < 4; ++i) {
            x = row + directions[i];
            y = column + directions[i + 1];
            if (x >= 0 && x < grid.size() &&
                y >= 0 && y < grid[0].size() &&
                !visited[x][y] &&
                grid[x][y]) {
                visited[x][y] = true;
                areaofIsland += 1 + countAreaofIsland_Method2(grid, visited, x, y);
            }
        }
        return areaofIsland;
    }

    int countAreaofIsland(std::vector<std::vector<int> >& grid,
                          std::vector<std::vector<bool> >& visited,
                          int row,
                          int column) {
        int areaofIsland = 0;
        if (row >= 0 && row < grid.size() &&
            column >= 0 && column < grid[0].size() &&
            !visited[row][column] &&
            grid[row][column] == 1) {
            visited[row][column] = true;
            areaofIsland += 1 + countAreaofIsland(grid, visited, row - 1, column)
                              + countAreaofIsland(grid, visited, row + 1, column)
                              + countAreaofIsland(grid, visited, row, column + 1)
                              + countAreaofIsland(grid, visited, row, column - 1);
        }
        return areaofIsland;
    }

    int maxAreaofIsland(std::vector<std::vector<int> >& grid) {
        if (grid.empty()) {return 0;}
        int row = grid.size();
        int column = grid[0].size();
        int maxArea = 0;
        std::vector<std::vector<bool> > visited(row, std::vector<bool>(column, false));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (!visited[i][j] && grid[i][j]) {
                    maxArea = std::max(maxArea, countAreaofIsland(grid, visited, i, j));
                }
            }
        }
        return maxArea;
    }
};