#include <iostream>
#include <vector>

class Solution {
public:
    bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
        if (flowerbed.empty()) {return false;}
        int emptys = 1;
        int plotAvaliabla = 0;
        for (const int val : flowerbed) {
            if (val == 1) {
                plotAvaliabla += (emptys - 1) / 2;
                emptys = 0;
                if (plotAvaliabla >= n) {return true;}
            }
            else {emptys++;}
        }
        plotAvaliabla += (emptys) / 2;
        return plotAvaliabla >= n;
    } 
};