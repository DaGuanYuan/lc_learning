#include <iostream>
#include <vector>

class Solution {
public:
    void printMatrixInCircle(std::vector<std::vector<int> >& matrix) {
        if (matrix.empty()) {
            printf("The Matrix is Empty!\n");
            return;
        }
        int left = 0;
        int top = 0;
        int bottom = matrix.size() - 1;
        int right = matrix[0].size() - 1;
        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; i++) {
                printf("%d ", matrix[top][i]);
            }
            top++;
            
            for (int i = top; i <= bottom; i++) {
                printf("%d ", matrix[i][right]);
            }
            right--;

            for (int i = right; i >= left && top <= bottom; i--) {
                printf("%d ", matrix[bottom][i]);
            }
            bottom--;

            for (int i = bottom; i >= top && left <= right; i--) {
                printf("%d ", matrix[i][left]);
            }
            left++;
        }
        printf("\n");
    }
};

int main(int argc, const char** argv) {
    Solution s;
    std::vector<std::vector<int> > test1 {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    std::vector<std::vector<int> > test2 {
        {1, 2, 3, 4}
    };
    std::vector<std::vector<int> > test3 {
        {1},
        {2},
        {3},
        {4},
    };
    std::vector<std::vector<int> > test4 {};
    s.printMatrixInCircle(test4);
    return 0;
}