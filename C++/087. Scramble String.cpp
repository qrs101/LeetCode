#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        auto n = int(s1.size());
        if (n == 0)
            return false;
        if (s1 == s2)
            return true;
        typedef vector<vector<bool>> array_2d;
        vector<array_2d> dp (n + 1, array_2d(n, vector<bool>(n, false)));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                if (s1[i] == s2[j])
                    dp[1][i][j] = true;
        }
        for (int k = 2; k <= n; k++) {
            for (int i = 0; i <= n - k; i++) {
                string str1 = s1.substr(i, k);
                for (int j = 0; j <= n - k; j++) {
                    string str2 = s2.substr(j, k);
                    for (int len = 1; len < k; len++) {
                        bool A = dp[len][i][j] && dp[k - len][i + len][j + len];
                        bool B = dp[len][i][j + k - len] && dp[k - len][i + len][j];
                        if (A || B) {
                            dp[k][i][j] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[n][0][0];
    }
};