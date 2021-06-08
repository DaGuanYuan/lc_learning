#include <iostream>
#include <vector>

class Solution {
public:
    int candy(std::vector<int>& rating) {
        if (rating.empty()) {return 0;}
        int n = rating.size();
        if (n == 1) {return 1;}
        int minRating = INT32_MAX;
        int minRatingIndex = 0;
        for (int i = 0; i < n; i++) {
            if (minRating > rating[i]) {
                minRating = rating[i];
                minRatingIndex = i;
            }
        }
        int candy = 1;
        int candyinTotal = 1;
        int left = minRatingIndex - 1;
        int continuous = 0;
        while (left >= 0) {
            if (rating[left] > rating[left + 1]) {candy++;}
            else if (rating[left] == rating[left + 1]) {candy = 1;}
            else {
                int rightCandy = candy;
                while (left >= 0 && rating[left] < rating[left + 1]) {
                    if (candy == 1) {
                        continuous++;
                        if (continuous > rightCandy) {candyinTotal++;}
                        candyinTotal += continuous; //rating[right - 1] should + 1
                    }
                    candy = 1;
                    left--;
                    candyinTotal += candy;
                }
                continuous = 0;
                continue;
            }
            candyinTotal += candy;
            left--;  
        }
        int right = minRatingIndex + 1;
        candy = 1;
        while (right < n) {
            if (rating[right] > rating[right - 1]) {candy++;}
            else if (rating[right] == rating[right - 1]) {candy = 1;}
            else {
                int leftCandy = candy;
                while (right < n && rating[right] < rating[right - 1]) {
                    if (candy == 1) {
                        continuous++;
                        if (continuous > leftCandy) {candyinTotal++;}
                        candyinTotal += continuous; //rating[right - 1] should + 1
                    }
                    candy = 1;
                    right++;
                    candyinTotal += candy;
                }
                continuous = 0;
                continue;
            }

            candyinTotal += candy;
            right++;
        }
        return candyinTotal;
    }
};