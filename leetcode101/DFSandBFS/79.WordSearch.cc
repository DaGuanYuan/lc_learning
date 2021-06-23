#include <iostream>
#include <vector>
#include <string.h>

class Solution {
public:
    std::vector<int> directions{1, 0, -1, 0, 1};

    bool exsitinBoard_Solution1(std::vector<std::vector<char> >& board,
                      std::string& word,
                      std::vector<std::vector<bool> >& visited,
                      int& wordPos,
                      int row,
                      int column) {
        if (wordPos == word.size()) {return true;}
        if (row < 0 || row >= board.size() ||
            column < 0 || column >= board[0].size() ||
            word[wordPos] != board[row][column] ||
            visited[row][column]) {return false;}
        int x, y;
        visited[row][column] = true;
        ++wordPos;
        bool res = false;
        for (int i = 0; i < 4; ++i) {
            x = row + directions[i];
            y = column + directions[i + 1];
            res = res || exsitinBoard_Solution1(board, word, visited, wordPos, x, y);
            if (res) {return true;}
        }
        visited[row][column] = false;
        --wordPos;
        return res;
    }

    bool exsitinBoard_Solution1(std::vector<std::vector<char> >& board, std::string& word) {
        if (board.empty()) {return false;}
        int row = board.size();
        int column = board[0].size();
        std::vector<std::vector<bool> > visited(row, std::vector<bool>(column, false));
        bool res = false;
        int wordPos = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                res = res || exsitinBoard_Solution1(board, word, visited, wordPos, i, j);
                if (res) {return true;}
            }
        }
        return res;
    }

bool exsitinBoard_Solution2(std::vector<std::vector<char> >& board,
                      std::string& word,
                      std::vector<std::vector<bool> >& visited,
                      int& wordPos,
                      int row,
                      int column) {
        if (wordPos == word.size()) {return true;}
        int x, y;
        bool res = false;
        for (int i = 0; i < 4; ++i) {
            x = row + directions[i];
            y = column + directions[i + 1];
            if (x >= 0 && x < board.size() &&
                y >= 0 && y < board[0].size() &&
                !visited[x][y] &&
                board[x][y] == word[wordPos]) {
                ++wordPos;
                visited[x][y] = true;
                res = res || exsitinBoard_Solution2(board, word, visited, wordPos, x, y);
                if (res) {return true;}
                --wordPos;
                visited[x][y] = false;
            }

        }
        return res;
    }

    bool exsitinBoard_Solution2(std::vector<std::vector<char> >& board, std::string& word) {
        if (board.empty()) {return false;}
        int row = board.size();
        int column = board[0].size();
        std::vector<std::vector<bool> > visited(row, std::vector<bool>(column, false));
        bool res = false;
        int wordPos = 1;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (board[i][j] != word[0]) {continue;}
                visited[i][j] = true;
                res = res || exsitinBoard_Solution2(board, word, visited, wordPos, i, j);
                if (res) {return true;}
                visited[i][j] = false;
            }
        }
        return res;
    }
};