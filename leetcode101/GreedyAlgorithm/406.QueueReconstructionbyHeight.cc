#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int> > reconstructQueue(std::vector<std::vector<int> >& people) {
        std::vector<int> temp = {INT32_MAX, 0}; 
        std::vector<std::vector<int> > queue(people.size(), temp);
        if (people.empty()) {return queue;}
        std::sort(people.begin(), people.end(), 
            [](std::vector<int>& a, std::vector<int>& b) {
                return a[1] < b[1];
            });
        int before = 0;
        queue[0] = people[0];
        for (int i = 1; i < people.size(); i++) {
            before = people[i][1];
            for (int j = 0; j <= i; j++) {
                if (before == 0) {
                    while (people[i][0] >= queue[j][0]) {j++;}
                    for (int k = i - 1; k >= j; k--) {
                        queue[k + 1] = queue[k];
                    }
                    queue[j] = people[i];
                    break;
                }
                if (queue[j][0] >= people[i][0]) {before--;}
            }
        }
        return queue;
    }
};