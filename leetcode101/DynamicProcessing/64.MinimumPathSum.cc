#include <iostream>
#include <vector>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int> >& grid) {
        if (grid.empty()) {return 0;}
        int row = grid.size();
        int column = grid[0].size();
        std::vector<std::vector<int> > dp(row, std::vector<int>(column, 0));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < row; ++i) {dp[i][0] = dp[i - 1][0] + grid[i][0];}
        for (int j = 1; j < column; ++j) {dp[0][j] = dp[0][j - 1] + grid[0][j];}
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < column; ++j) {
                dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[row - 1][column - 1];
    }

    int minPathSum_withCompression(std::vector<std::vector<int> >& grid) {
        if (grid.empty()) {return 0;}
        int row = grid.size();
        int column = grid[0].size();
        std::vector<int> dp(column, 0);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (i == 0 && j == 0) {dp[j] = grid[0][0];}
                else if (i == 0) {dp[j] = dp[j - 1] + grid[0][j];}
                else if (j == 0) {dp[j] = dp[j] + grid[i][0];}
                else {dp[j] = std::min(dp[j - 1], dp[j]) + grid[i][j];}
            }
        }
        return dp[column - 1];
    }
};