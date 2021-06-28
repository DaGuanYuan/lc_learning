#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    std::vector<int> directions{-1, 0, 1, 0, -1};

    void findIsland1(std::vector<std::vector<int> >& grid,
                     std::queue<std::pair<int, int> >& q,
                     int row,
                     int column) {
        if (row >= grid.size() || row < 0 ||
            column >= grid[0].size() || column < 0 ||
            grid[row][column] == 2) {return;}

        if (grid[row][column] == 0) {
            q.push(std::make_pair(row, column));
            return;    
        }
        int x, y;
        grid[row][column] = 2;
        for (int i = 0; i < 4; ++i) {
            x = row + directions[i];
            y = column + directions[i + 1];
            findIsland1(grid, q, x, y);
        }
    }

    int shortestBridge(std::vector<std::vector<int> >& grid) {
        if (grid.empty()) {return 0;}
        int row = grid.size();
        int column = grid[0].size();
        std::queue<std::pair<int, int> > q;
        bool reachIsland1 = false;
        for (int r = 0; r < row; ++r) {
            if (reachIsland1) {break;}
            for (int c = 0; c < column; ++c) {
                if (grid[r][c] == 1) {
                    reachIsland1 = true;
                    findIsland1(grid, q, r, c);
                    break;
                }
            }
        }
        
        int distance = 0;
        int row_new, column_new;
        while (!q.empty()) {
            // Here should notice that if you set gird = 2 at
            // this moment will lead to extra O((M-1)*N) complexity
            // since much moreduplicated coordinates would be 
            // pushed into queue

            //grid[q.front().first][q.front().second] = 2;
            int qSize = q.size();
            ++distance;
            while (qSize) {
                for (int i = 0; i < 4; ++i) {
                    row_new = q.front().first + directions[i];
                    column_new = q.front().second + directions[i + 1];
                    if (row_new >= 0 && row_new < row &&
                        column_new >= 0 && column_new < column) {
                        if (grid[row_new][column_new] == 2) {continue;}
                        if (grid[row_new][column_new] == 1) {return distance;}
                        q.push(std::make_pair(row_new, column_new));
                        // But, if you set grid = 2 in the operation step
                        // only O(M) complexity would be led into
                        // It's somewhat vary interesting
                        grid[row_new][column_new] = 2;
                    }
                }
                q.pop();
                --qSize;
            }
        }
        return 0;
    }
};