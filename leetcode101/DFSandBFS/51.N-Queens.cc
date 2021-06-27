#include <iostream>
#include <vector>
#include <string.h>
#include <unordered_map>

class Solution{
public:
    void setFalse(int n, 
                  std::vector<std::vector<bool> >& isValid,
                  std::vector<std::vector<bool> >& thisTurn,
                  int x_index,
                  int y_index) {
        for (int i = x_index; i < n; ++i) {
            if (isValid[i][y_index]) {
                thisTurn[i][y_index] = true;
                isValid[i][y_index] = false;
            }
        }

        for (int i = y_index; i < n; ++i) {
            if (isValid[x_index][i]) {
                thisTurn[x_index][i] = true;
                isValid[x_index][i] = false;
            }
        }

        int i = 0;
        // x_index++ is equal to y_axis++, meaning turn bottom !!!!!!
        // y_index++ is equal to x_axis++, meaning turn right !!!!!!
        for (int j = y_index; j < n; ++j) {
            i = j + x_index - y_index;
            if (i < n && i >= 0 && isValid[i][j]) {
                thisTurn[i][j] = true;
                isValid[i][j] = false;
            }
        }

        for (int j = y_index; j >= 0; --j) {
            i = x_index + y_index - j;
            if (i < n && i >= 0 && isValid[i][j]) {
                thisTurn[i][j] = true;
                isValid[i][j] = false;
            }
        }
    }

    void setTrue(int n, 
                 std::vector<std::vector<bool> >& isValid,
                 std::vector<std::vector<bool> >& thisTurn,
                 int x_index,
                 int y_index) {
        for (int i = x_index; i < n; ++i) {
            if (thisTurn[i][y_index] == true) {
                thisTurn[i][y_index] = false;
                isValid[i][y_index] = true;
            }
        }
        for (int i = y_index; i < n; ++i) {
            if (thisTurn[x_index][i] == true) {
                thisTurn[x_index][i] = false;
                isValid[x_index][i] = true;
            }  
        }
        
        int i = 0;
        for (int j = y_index; j < n; ++j) {
            i = j + x_index - y_index;
            if (i < n && i >= 0 && thisTurn[i][j]) {
                thisTurn[i][j] = false;
                isValid[i][j] = true;
            }
        }

        for (int j = y_index; j >= 0; --j) {
            i = x_index + y_index - j;
            if (i < n && i >= 0 && thisTurn[i][j]) {
                thisTurn[i][j] = false;
                isValid[i][j] = true;
            }
        }
    }

    void solveNQueens_S2(int n,
                        int& cnt,
                        std::vector<std::vector<std::string> >& res,
                        std::vector<std::string>& oneBoard,
                        std::vector<std::vector<bool> >& isValid,
                        int x_index,
                        int y_index) {
        if (cnt == n) {
            res.push_back(oneBoard);
            return;
        }

        if (x_index < 0 || x_index >= n ||
            y_index < 0 || y_index >= n ||
            !isValid[x_index][y_index]) {
            return;
        }
        oneBoard[x_index][y_index] = 'Q';
        ++cnt;
        std::vector<std::vector<bool> > thisTurn(n, std::vector<bool>(n, false));
        setFalse(n, isValid, thisTurn, x_index, y_index);
        // For n = 1, or more generally, the last row must amd 
        // only need once, y_index could be any value, where 
        // y_index(parameter) < y_index < n
        // that is because of "first searching" strategy 
        solveNQueens_S2(n, cnt, res, oneBoard, isValid, x_index, y_index);
        for (int i = x_index + 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                solveNQueens_S2(n, cnt, res, oneBoard, isValid, i, j);
            }
        }
        oneBoard[x_index][y_index] = '.';
        --cnt;
        setTrue(n, isValid, thisTurn, x_index, y_index);

    }

    std::vector<std::vector<std::string> > solveNQueens_S2(int n) {
        if (n <= 0) {return {};}
        std::vector<std::vector<std::string>> res;
        std::vector<std::string> oneBoard(n, std::string(n, '.'));
        std::vector<std::vector<bool> > isValid(n, std::vector<bool>(n, true));
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            solveNQueens_S2(n, cnt, res, oneBoard, isValid, 0, j);
            isValid[0][j] = false;
        }
        return res;
    }

    void solveNQueens(int n,
                      std::vector<std::vector<std::string> >& res,
                      std::vector<std::string>& oneBoard,
                      std::vector<bool>& columnNotValid,
                      std::vector<bool>& ldiagNotValid,
                      std::vector<bool>& rdiagNotValid,
                      int row) {
        if (row == n) {
            res.push_back(oneBoard);
            return;
        }
        // ldiagNotValid, from left top to right bottom, where
        // we have -(n - 1) <= row - i <= n - 1, so we establish
        // a vector<bool> sized 2*n - 1 and normalize the range to
        // 0~2n-2 by add n - 1
        // As the same, rdiagNotValid plots from right top to left 
        // bottom, where 0 <= row + i <= 2n - 2
        for (int i = 0; i < n; ++i) {
            if (columnNotValid[i] ||
                ldiagNotValid[row - i + n - 1] ||
                rdiagNotValid[row + i]) {continue;}
            oneBoard[row][i] = 'Q';
            columnNotValid[i] = ldiagNotValid[row - i + n - 1] = rdiagNotValid[row + i] = true;
            solveNQueens(n, res, oneBoard, columnNotValid, ldiagNotValid, rdiagNotValid, row + 1);
            oneBoard[row][i] = '.';
            columnNotValid[i] = ldiagNotValid[row - i + n - 1] = rdiagNotValid[row + i] = false;
        }
    }

    std::vector<std::vector<std::string> > solveNQueens(int n) {
        if (n <= 0) {return {};}
        std::vector<std::vector<std::string> > res;
        std::vector<std::string> oneBoard(n, std::string(n, '.'));
        std::vector<bool> columnNotValid(n, false);
        std::vector<bool> ldiagNotValid(2 * n - 1, false);
        std::vector<bool> rdiagNotValid(2 * n - 1, false);
        solveNQueens(n, res, oneBoard, columnNotValid, ldiagNotValid, rdiagNotValid, 0);
        return res;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    s.solveNQueens(9);
    return 0;
} 