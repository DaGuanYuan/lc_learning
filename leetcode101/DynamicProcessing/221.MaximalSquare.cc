#include <iostream>
#include <vector>

class Solution {
public:
    int maximalSquare_Myself(std::vector<std::vector<char> >& matrix) {
        if (matrix.empty()) {return 0;}
        int row = matrix.size();
        int column = matrix[0].size();
        std::vector<std::vector<int> > dp(row + 1, std::vector<int>(column + 1, 0));
        int maxSideLength = 0;
        int boarder = 0;
        for (int i = 1; i <= row; ++i) {
            for (int j = 1; j <= column; ++j) {
                boarder = std::min(dp[i - 1][j - 1], std::min(i - 1, j - 1));
                for (int k = 0; k <= boarder; ++k) {
                    if (matrix[i - k - 1][j - 1] == '0' || matrix[i - 1][j - k - 1] == '0') {break;}
                    ++dp[i][j];
                }
                maxSideLength = std::max(maxSideLength, dp[i][j]);            
            }
        }
        return maxSideLength * maxSideLength;
    }

    int maximalSquare(std::vector<std::vector<char> >& matrix) {
        if (matrix.empty()) {return 0;}
        int row = matrix.size();
        int column = matrix[0].size();
        std::vector<std::vector<int> > dp(row + 1, std::vector<int>(column + 1, 0));
        int maxSideLength = 0;
        int boarder = 0;
        for (int i = 1; i <= row; ++i) {
            for (int j = 1; j <= column; ++j) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = 1 + std::min(dp[i - 1][j - 1], std::min(dp[i][j - 1], dp[i - 1][j]));
                    maxSideLength = std::max(maxSideLength, dp[i][j]);
                }
            }
        }
        return maxSideLength * maxSideLength;
    }
};
