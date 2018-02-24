#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        auto m = int(word1.size());
        auto n = int(word2.size());
        string str1 = "#" + word1;
        string str2 = "#" + word2;
        vector<vector<int>> dp (m + 1, vector<int>(n + 1));
        for (int i = 0; i <= n; i++)
            dp[0][i] = i;
        for (int i = 1; i <= m; i++) {
            dp[i][0] = i;
            for (int j = 1; j <= n; j++) {
                if (str1[i] == str2[j])
                    dp[i][j] = dp[i - 1][j - 1];
                else {
                    int tmp = min(dp[i - 1][j - 1], dp[i - 1][j]);
                    tmp = min(tmp, dp[i][j - 1]);
                    dp[i][j] = tmp + 1;
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution so;
    int ans = so.minDistance("", "");
    cout << ans << endl;
    return 0;
}