#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.size() <= 1)
            return 0;
        int k = 2;
        int N = int(prices.size());
        std::vector<std::vector<int>> dp (k + 1, std::vector<int>(N, 0));
        for (int i = 1; i <= k; i++) {
            int Max = dp[i - 1][0] - prices[0];
            for (int j = 1; j < N; j++) {
                Max = std::max(Max, dp[i - 1][j] - prices[j]);
                dp[i][j] = std::max(dp[i][j - 1], Max + prices[j]);
            }
        }
        return dp[k][N - 1];
    }
};