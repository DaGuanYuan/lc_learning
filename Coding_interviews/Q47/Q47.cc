#include <iostream>
#include <vector>

class Solution {
public:
    int getMaxGiftValue(std::vector<std::vector<int> >& grid) {
        if (grid.empty()) {return 0;}
        int row = grid.size();
        int column = grid[0].size();
        std::vector<std::vector<int> > dp(row + 1, std::vector<int>(column + 1, 0));
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= column; j++) {
                dp[i][j] = grid[i - 1][j - 1] + std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[row][column];
    }
};

int main(int argc, const char** argv) {
    Solution s;
    // empty, only 1 number
    // only have 1 column
    // only have 1 row
    // have repeated numbers
    // normal
    std::vector<std::vector<int> > grid {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    int maxValueofGifts = s.getMaxGiftValue(grid);
    printf("The maximum value of gifts you can obtain is %d\n", maxValueofGifts);
    return 0;
}