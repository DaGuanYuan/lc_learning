#include <iostream>
#include <vector>

class Solution {
public:
    void combineCore(std::vector<std::vector<int> >& res,
                     std::vector<int>& temp,
                     int pos,
                     int n,
                     int& k) {
        if (k == 0) {
            res.push_back(temp);
            return;
        }

        for (int i = pos; i <= n; ++i) {
            temp.push_back(i);
            --k;
            combineCore(res, temp, i + 1, n, k);
            ++k;
            temp.pop_back();
        }
    }

    std::vector<std::vector<int> > combine(int n, int k) {
        if (k > n) {return {};}
        std::vector<std::vector<int> > res;
        std::vector<int> temp;
        int pos = 1;
        combineCore(res, temp, pos, n, k);
        return res;
    }
};