#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        auto n = int(s1.size());
        typedef vector<vector<bool>> array_2d;
        vector<array_2d> dp(n, array_2d(n, vector<bool>(n, false)));

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n - k; i++) {
                for (int j = 0; j < n - k; j++) {
                    if (k == 0 && s1[i] == s2[j])
                        dp[k][i][j] = true;
                    for (int len = 0; len < k; len++) {
                        bool A = dp[len][i][j] && dp[k - len- 1][i + len + 1][j + len + 1];
                        bool B = dp[len][i][k - len + j] && dp[k - len - 1][i + len + 1][j];
                        if (A || B) {
                            dp[k][i][j] = true;
                            break;
                        }
                    }
                }
            }
        }

        return dp[n - 1][0][0];
    }
};