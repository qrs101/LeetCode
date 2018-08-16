#include <iostream>
#include <vector>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        auto m = int(grid.size()), n = int(grid[0].size());
        std::vector<std::vector<int>> dp (m, std::vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for (int j = 1; j < n; j++)
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        for (int i = 1; i < m; i++)
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                int Min = dp[i - 1][j] <= dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
                dp[i][j] = Min + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};