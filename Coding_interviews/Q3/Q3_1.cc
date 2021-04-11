#include <iostream>
#include <vector>
#define ERROR false

//Given range of array {0, 1, 2, ..., n-1}
class Solution {
public:
    bool Duplicated(std::vector<int>& array, int n) {
        if (array.empty()) {return ERROR;}
        for(std::vector<int>::iterator it = array.begin(); it != array.end(); it++) {
            if (*it >= n) {
            printf("Out of range!\n");
            return ERROR;
            }
        }
        if (array.size() != n) {return ERROR;}

        int temp = 0;
        for (int i = 0; i < n; i++) { 
            while (array[i] != i) {
                if (array[i] == array[array[i]]) {return true;}
                temp = array[i];
                array[i] = array[temp];
                array[temp] = temp;
            }
        }
        return false;
    }
};

int main() {
    std::vector<int> v{0, 5, 1111, 3, 1, 2};
    int n = v.size();
    Solution s;
    bool result = s.Duplicated(v, n);
    if (result) {printf("Same elements found\n");}
    else {printf("Every element is unique\n");}
    return 0;
}   