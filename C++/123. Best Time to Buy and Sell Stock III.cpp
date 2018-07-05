#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1)
            return 0;
        int k = 2;
        int N = int(prices.size());
        vector<vector<int>> dp (k + 1, vector<int>(N, 0));
        for (int i = 1; i <= k; i++) {
            int Max = dp[i - 1][0] - prices[0];
            for (int j = 1; j < N; j++) {
                Max = max(Max, dp[i - 1][j] - prices[j]);
                dp[i][j] = max(dp[i][j - 1], Max + prices[j]);
            }
        }
        return dp[k][N - 1];
    }
};