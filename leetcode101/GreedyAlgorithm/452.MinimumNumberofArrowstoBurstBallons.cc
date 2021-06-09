#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int findMinArrowShot(std::vector<std::vector<int> >& balloons) {
        if (balloons.empty()) {return 0;}
        std::sort(balloons.begin(), balloons.end(), 
            [](std::vector<int>& a, std::vector<int>& b) {
                return a[0] > b[0];
            });
        int minArrow = 0;
        int front = balloons[0][1];
        for (int i = 1; i < balloons.size(); i++) {
            if (balloons[i][0] > front) {
                minArrow++;
                front = balloons[i][0];    
            }
        }
        return minArrow;
    }
};