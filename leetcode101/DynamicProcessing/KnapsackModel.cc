#include <iostream>
#include <vector>

class Solution {
public:
    int knapsack(std::vector<int>& weights,
                 std::vector<int>& values,
                 int N,
                 int W) {
        // N = Number of goods; W = The volume of the knapsack
        std::vector<std::vector<int> > dp(N + 1, std::vector<int>(W + 1, 0));
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= W; ++j) {
                if (weights[i - 1] <= j) {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
                }
                else {dp[i][j] = dp[i - 1][j];}
            }
        }
        return dp[N][W];
    }

    int knapsack_compression(std::vector<int>& weights,
                             std::vector<int>& values,
                             int N,
                             int W) {
        std::vector<int> dp(W + 1, 0);
        for (int i = 1; i <= N; ++i) {
            int w = weights[i - 1];
            int v = values[i - 1];
            for (int j = W; j >= w; --j) {
                dp[j] = std::max(dp[j], dp[j - w] + v);
            }
        }
        return dp[W];
    }

    int unboundedKnapsack(std::vector<int>& weights,
                          std::vector<int>& values,
                          int N,
                          int W) {
        std::vector<std::vector<int> > dp(N + 1, std::vector<int>(W + 1, 0));
        for (int i = 1; i <= N; ++i) {
            int w = weights[i - 1], v = values[i - 1];
            for (int j = 1; j <= W; ++j) {
                if (j >= w) {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - w] + v);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[N][W];
    }

    int unboundKnapsack_compression(std::vector<int>& weights,
                                    std::vector<int>& values,
                                    int N,
                                    int W) {
        std::vector<int> dp(W + 1, 0);
        for (int i = 1; i <= N; ++i) {
            int w = weights[i - 1], v = values[i - 1];
            for (int j = w; j <= W; ++j) {
                dp[j] = std::max(dp[j], dp[j - w] + v);
            }
        }
        return dp[W];
    }
}; 