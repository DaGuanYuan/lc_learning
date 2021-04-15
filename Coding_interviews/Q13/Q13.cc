#include <iostream>
#include <vector>

class Solution {
public:
    bool addLessk(int row, int column, int k) {
        int sum = 0;
        while (row) {
            sum += (row % 10);
            row /= 10;
        }
        while (column) {
            sum += (column % 10);
            column /= 10;
        }
        return sum <= k;
    }

    int movingCountCore(std::vector<std::vector<bool> >& visted,
                        int rows,
                        int columns,
                        int row,
                        int column,
                        int k) {
        int res = 0;
        if (row >= 0 && row < rows
            && column >= 0 && column < columns
            && !visted[row][column]
            && addLessk(row, column, k)) {
            visted[row][column] = true;
            res = 1 + movingCountCore(visted, rows, columns, row + 1, column, k)
                    + movingCountCore(visted, rows, columns, row - 1, column, k)
                    + movingCountCore(visted, rows, columns, row, column + 1, k)
                    + movingCountCore(visted, rows, columns, row, column - 1, k);
        }
        return res;
    }

    int movingCount(int rows, int columns, int k) {
        if (rows < 1 || columns < 1 || k < 0) {return 0;}
        std::vector<std::vector<bool> > visited(rows, std::vector<bool>(columns, false));
        return movingCountCore(visited, rows, columns, 0, 0, k);
    }
};

int main(int argc, const char** argv) {
    Solution s;
    int rows = 5;
    int columns = 4;
    int k = 0;
    printf("%d\n", s.movingCount(rows, columns, k));
    return 0;
}