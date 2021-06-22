#include <iostream>
#include <vector>

class Solution {
public:
    void combineCore(std::vector<std::vector<int> >& res,
                     std::vector<int>& temp,
                     std::vector<bool>& visited,
                     int n,
                     int k) {
        for (int i = 0; i < n; ++i) {
            temp.push_back(i);
            visited[i] = true;
            --k;
            if (k == 0) {
                res.push_back(temp);
                temp.clear();
            }
            else {combineCore(res, temp, visited, n, k);}
            ++k;
        }

    }

    std::vector<std::vector<int> > combine(int n, int k) {
        if (k > n) {return {};}
        std::vector<std::vector<int> > res;
        std::vector<int> temp;
        std::vector<bool> visited(n, false);
        combineCore(res, temp, visited, n, k);
        return res;
    }
};