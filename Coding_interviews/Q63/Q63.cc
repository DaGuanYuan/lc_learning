#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.empty()) {return 0;}
        int maxPrice = INT32_MIN;
        int buyPrice = INT32_MAX;
        for (const int val : prices) {
            buyPrice = std::min(buyPrice, val);
            maxPrice = std::max(maxPrice, val - buyPrice);
        }
        return maxPrice;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    // array is empty, array has only one element / two elements
    // elements in array are monotonely increasing/decreasing
    // normal
    std::vector<int> prices {7, 1, 5, 3, 6, 4};
    int maxPrice = s.maxProfit(prices);
    printf("The maximum price you can obtain from the stock is: %d\n", maxPrice);
    return 0;
}
