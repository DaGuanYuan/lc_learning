#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> directions{-1, 0, 1, 0, -1};

    void findBorderRegions(std::vector<std::vector<char> >& board,
                           std::vector<std::vector<bool> >& connected2Border,
                           int row,
                           int column) {
        connected2Border[row][column] = true;
        int x, y;
        for (int i = 0; i < 4; ++i) {
            x = row + directions[i];
            y = column + directions[i + 1];
            if (x >= 0 && x < board.size() &&
                y >= 0 && y < board[0].size() &&
                board[x][y] == 'O' &&
                !connected2Border[x][y]) {
                findBorderRegions(board, connected2Border, x, y);
            }
        }
    }

    void surroundedRegions(std::vector<std::vector<char> >& board) {
        if (board.empty()) {return;}
        int row = board.size();
        int column = board[0].size();
        std::vector<std::vector<bool> > coneneted2Border(
            row, std::vector<bool>(column, false)
        );

        for (int i = 0; i < row; ++i) {
            if (board[i][0] == 'O' && !coneneted2Border[i][0]) {
                findBorderRegions(board, coneneted2Border, i, 0);
            }
            if (board[i][column - 1] == 'O' && !coneneted2Border[i][column - 1]) {
                findBorderRegions(board, coneneted2Border, i, column - 1);
            }            
        }

        for (int j = 0; j < column; ++j) {
            if (board[0][j] == 'O' && !coneneted2Border[0][j]) {
                findBorderRegions(board, coneneted2Border, 0, j);
            }
            if (board[row - 1][j] == 'O' && !coneneted2Border[row - 1][j]) {
                findBorderRegions(board, coneneted2Border, row - 1, j);
            }            
        }

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (board[i][j] == 'O' && !coneneted2Border[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};