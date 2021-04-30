#include <iostream>
#include <vector>

class Solution {
public:
    bool verifySeqofBSTCore(std::vector<int>& arr, int left, int right) {
        if (left >= right) {return true;}
        int firstLessThanRootIndex = left;
        while (arr[firstLessThanRootIndex] < arr[right]) {firstLessThanRootIndex++;}
        int isMatched = firstLessThanRootIndex;
        while (arr[isMatched] > arr[right]) {isMatched++;}
        return isMatched == right 
        && verifySeqofBSTCore(arr, left, firstLessThanRootIndex - 1)
        && verifySeqofBSTCore(arr, firstLessThanRootIndex, right - 1);
    }

    bool verifySeqofBST(std::vector<int>& arr) {
        if (arr.empty()) {return true;}
        int n = arr.size();
        return verifySeqofBSTCore(arr, 0, n - 1);
    }
};

int main (int argc, const char** argv) {
    Solution s;
    // arr.empty()
    // size = 1
    // all nodes only left tree
    // all nodes only right tree
    // normal
    std::vector<int> arr {5, 4, 3, 2, 1};
    if (s.verifySeqofBST(arr)) {printf("Arr is a Sequence of BST!\n");}
    else {printf("Arr is NOT a Sequence of BST\n");}
    return 0;
}