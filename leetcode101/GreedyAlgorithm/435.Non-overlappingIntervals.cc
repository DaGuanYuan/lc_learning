#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int eraseOverlapIntervals_Solution1(std::vector<std::vector<int> >& intervals) {
        int size = intervals.size();
        if (size < 2) {return 0;}
        std::sort(intervals.begin(), intervals.end()
                , [](std::vector<int>& a, std::vector<int>& b) {
                    return a[0] < b[0];
                });
        int front = 0;
        int behind = 1;
        int minErase = 0;
        while (behind < size) {
            if (intervals[front][0] == intervals[behind][0] &&
                intervals[front][1] <= intervals[behind][1]) {
                minErase++;
            }
            else if (intervals[front][0] < intervals[behind][0]) {
                if (intervals[front][1] >= intervals[behind][1]) {
                    minErase++;
                    front = behind;
                }
                else if (intervals[front][1] < intervals[behind][1]
                        && intervals[behind][0] < intervals[front][1]) {
                    minErase++;
                }
                else {front = behind;}
            }
            behind++;
        }
        return minErase;
    }

    // provided by leetcode 101
    int eraseOverlapIntervals_Solution2(std::vector<std::vector<int> >& intervals) {
        int size = intervals.size();
        if (size < 2) {return 0;}
        std::sort(intervals.begin(), intervals.end(), 
            [](std::vector<int>& a, std::vector<int>& b) {
                return a[1] < b[1];
            });
        int front = intervals[0][1];
        int minErase = 0;
        // i is behind
        for (int i = 1; i < size; i++) {
            if (intervals[i][0] < front) {minErase++;}
            else {front = intervals[i][1];}
        }
        return minErase;
    }
};