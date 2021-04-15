#include <iostream>
#include <vector>

class Solution {
public:
    bool hasPathCore(const std::vector<std::vector<char> >& matrix,
                     std::string s,
                     int columns,
                     int rows,
                     int column,
                     int row,
                     int pathLenth,
                     std::vector<std::vector<bool> >& visted) {
        if (pathLenth == s.size()) {return true;}
        bool hasPath = false;
        
        // It should be noticed that row >= o && row < rows must be in front of 
        // s[pathLenth] == matrix[row][column] and !visted[row][column], since 
        // jugdements are accomplished in order 
        if (row >= 0 && row < rows
            && column >= 0 && column < columns
            && s[pathLenth] == matrix[row][column]
            && !visted[row][column]) {
            pathLenth++;
            visted[row][column] = true;
            hasPath = hasPathCore(matrix, s, columns, rows, column + 1, row, pathLenth, visted)
                            || hasPathCore(matrix, s, columns, rows, column -1, row, pathLenth, visted)
                            || hasPathCore(matrix, s, columns, rows, column, row + 1, pathLenth, visted)
                            || hasPathCore(matrix, s, columns, rows, column, row - 1, pathLenth,visted);
            if (!hasPath) {
                pathLenth--;
                visted[row][column] = false;
            }
        }
        return hasPath; 
    }

    bool hasPath(const std::vector<std::vector<char> >& matrix, std::string s) {
        if (s.empty()) {return true;}
        int columns = matrix[0].size();  //列
        int rows = matrix.size();    //行
        if (matrix.empty() && !s.empty() || columns < 1 || rows < 1) {return false;}
        bool res = false;
        std::vector<std::vector<bool> > visited(rows, std::vector<bool>(columns, false));
        for (int row = 0; row < rows; row++) {
            for (int column = 0; column < columns; column++) {
                res = hasPathCore(matrix, s, columns, rows, column, row, 0, visited);
                if (res) {return res;}
            }
        }
        return res;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    std::vector<std::vector<char> > matrix{{'a', 'b', 't', 'g'},
                                           {'c', 'f', 'c', 's'},
                                           {'j', 'd', 'e' ,'h'}};
    std::string str{"btcedjcs"};
    bool result = s.hasPath(matrix, str);
    if (result) {printf("Found!\n");}
    else {printf("Not found\n");}
    return 0;
}