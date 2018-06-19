#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        auto m = int(word1.size());
        auto n = int(word2.size());
        word1 = '#' + word1;
        word2 = '#' + word2;
        vector<vector<int>> dp (m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i] == word2[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return m - dp[m][n] + n - dp[m][n];
    }
};

int main() {
    Solution so;
    int i = so.minDistance("s", "eat");
    cout << i << endl;
}