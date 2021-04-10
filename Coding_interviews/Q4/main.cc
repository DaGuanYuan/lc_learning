#include "vector"
#include "iostream"

class Solution {
public:
    bool Find(std::vector<std::vector<int> >& matrix, int number);
};

bool Solution::Find(std::vector<std::vector<int> >& matrix, int number) {
    if (matrix.empty()) {
        printf("Input matrix is empty, please have a check\n");
        return false;
    }
    int coloum = matrix.size() - 1;
    int row = matrix[0].size() - 1;
    int i = row;
    int j = 0;
    while (i >= 0 && j<=coloum) {
        if (matrix[j][i] == number) {return true;}
        else if (matrix[j][i] > number) {i--;}
        else {j++;}
    }
    return false;
}

int main() {
    std::vector<std::vector<int> > matrix;
    std::vector<int> a1{1, 2, 8, 9};
    std::vector<int> a2{2, 4, 9 ,12};
    std::vector<int> a3{4, 7, 10, 13};
    std::vector<int> a4{6, 8, 11 ,15};
    matrix.emplace_back(a1);
    matrix.emplace_back(a2);
    matrix.emplace_back(a3);
    matrix.emplace_back(a4);
    //matrix.clear();
    Solution s;
    int numbers = 9;
    bool result = s.Find(matrix, numbers);
    if (result) {printf("Found\n");}
    else {printf("Not found\n");}
    return 0;
}