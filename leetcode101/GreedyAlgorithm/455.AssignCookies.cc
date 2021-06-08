#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxContentChildren(std::vector<int>& g, std::vector<int>& s) {
        if (g.empty() || s.empty()) {return 0;}
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int children = 0;
        int cookies = 0;
        while (children < g.size() && cookies < s.size()) {
            if (g[children] <= s[cookies]) {children++;}
            cookies++;
        }
        return children;
    }
};