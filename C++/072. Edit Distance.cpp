#include <iostream>
#include <vector>

class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        int m = int(word1.size()), n = int(word2.size());
        word1 = '#' + word1;
        word2 = '#' + word2;
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        for (int i = 0; i < m + 1; i++)
            dp[i][0] = i;
        for (int i = 0; i < n + 1; i++)
            dp[0][i] = i;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i] == word2[j])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = std::min(std::min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
            }
        }
        return dp[m][n];
    }
};