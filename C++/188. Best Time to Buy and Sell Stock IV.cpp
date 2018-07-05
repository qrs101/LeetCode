#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int N = int(prices.size());
        if (N == 0)
            return 0;
        if (k >= N) {
            int res = 0;
            for (int i = 1; i < N; i++) {
                if (prices[i] > prices[i - 1])
                    res += prices[i] - prices[i - 1];
            }
            return res;
        }
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