#include <iostream>
#include <vector>
#include <tuple>

class Solution {
public:
    void solveSudoku(std::vector<std::vector<char> >& board,
                     std::vector<std::vector<bool> >& column,
                     std::vector<std::vector<bool> >& row,
                     std::vector<std::vector<std::vector<bool> > >& block,
                     std::vector<std::pair<int, int> >& spaceToFill,
                     int pos) {
        if (pos == spaceToFill.size()) {
            valid = true;
            return;
        }
        int x, y;
        std::tie(x, y) = spaceToFill[pos];
        for (int val = 1; val <= 9 && !valid; ++val) {
            if (!row[x][val - 1] && !column[y][val - 1] &&
                !block[x / 3][y / 3][val - 1]) {
                board[x][y] = val + '0';
                row[x][val - 1] = column[y][val - 1] = block[x/3][y/3][val - 1] = true;
                solveSudoku(board, column, row, block, spaceToFill, pos + 1);
                row[x][val - 1] = column[y][val - 1] = block[x/3][y/3][val - 1] = false;
            }
        }
    }

    void solveSudoku(std::vector<std::vector<char> >& board) {
        std::vector<std::vector<bool> > column(9, std::vector<bool>(9, false));
        std::vector<std::vector<bool> > row(9, std::vector<bool>(9, false));
        std::vector<std::vector<std::vector<bool> > > block(
            3, std::vector<std::vector<bool> >(
            3, std::vector<bool>(9, false)));
        std::vector<std::pair<int, int> > spcaeToFill;
        int val = 0;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {spcaeToFill.emplace_back(i, j);}
                else {
                    val = board[i][j] - '0' - 1;
                    row[i][val] = column[j][val] = block[i / 3][j / 3][val] = true;
                }
            }
        }
        solveSudoku(board, column, row, block, spcaeToFill, 0);
    }

    bool valid = false;
};