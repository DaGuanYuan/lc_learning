#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int findMinArrowShot_Soluiton1(std::vector<std::vector<int> >& balloons) {
        if (balloons.empty()) {return 0;}
        std::sort(balloons.begin(), balloons.end(), 
            [](std::vector<int>& a, std::vector<int>& b) {
                return a[0] < b[0];
            });
        int minArrow = 1;
        int front = balloons[0][1];
        for (int i = 1; i < balloons.size(); i++) {
            if (balloons[i][0] > front) {
                minArrow++;
                front = balloons[i][1];    
            }
            front = std::min(front, balloons[i][1]);
        }
        // minArrow++; // The last balloon(s) should be shot, in fact we can initial minArrow as 1;
        return minArrow;
    }

    int findMinArrowShot_Solution2(std::vector<std::vector<int> >& balloons) {
        if (balloons.empty()) {return 0;}
        std::sort(balloons.begin(), balloons.end(),
            [](std::vector<int>& a, std::vector<int>& b) {
                return a[1] < b[1];
            });
        int minArrow = 1;
        int front = balloons[0][1];
        for (int i = 1; i < balloons.size(); i++) {
            if (balloons[i][0] > front) {
                minArrow++;
                front = balloons[i][1];
            }
        }
        return minArrow;
    }
};