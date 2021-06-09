#include <iostream>
#include <vector>
#include <numeric>

class Solution {
public:
    int candy_Soluton1(std::vector<int>& ratings) {
        int size = ratings.size();
        if (size < 2) {return size;}
        std::vector<int> candySplit(size, 1);
        for (int i = 1; i < size; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candySplit[i] = candySplit[i - 1] + 1;
            }
        }
        for (int i = size - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candySplit[i] = std::max(candySplit[i], candySplit[i + 1] + 1);
            }
        }
        int totalCandy = std::accumulate(candySplit.begin(), candySplit.end(), 0);
        return totalCandy;
    }

    int candy_Solution2(std::vector<int>& ratings) {
        int size = ratings.size();
        if (size < 2) {return size;}
        int increase = 1;
        int currentCandy = 1;
        int totalCandy = 1;
        int decrease = 0;
        for (int i = 1; i < size; i++) {
            if (ratings[i] >= ratings[i - 1]) {
                decrease = 0;
                currentCandy = ratings[i] == ratings[i - 1] ? 1 : currentCandy + 1;
                totalCandy += currentCandy;
                increase = currentCandy;
            }
            else {
                decrease++;
                if (decrease == increase) {decrease++;}
                totalCandy += decrease;
                currentCandy = 1;
            }
        }
        return totalCandy;
    }
};