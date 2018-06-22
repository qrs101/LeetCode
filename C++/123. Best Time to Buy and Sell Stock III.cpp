#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1)
            return 0;
        unsigned int K = 2;
        int n = int(prices.size());
        vector<vector<int>> dp (K + 1, vector<int>(n, 0));
        for (int k = 1; k <= K; k++) {
            int tmpMax = dp[k - 1][0] - prices[0];
            for (int i = 1; i < n; i++) {
                tmpMax = max(tmpMax, dp[k - 1][i] - prices[i]);
                dp[k][i] = max(dp[k][i - 1], prices[i] + tmpMax);
            }
        }
        return dp[K][n - 1];
    }
};