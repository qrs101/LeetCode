#include <iostream>
#include <vector>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        auto M = int(s.size());
        auto N = int(p.size());
        std::vector<std::vector<bool>> dp (N + 1, std::vector<bool>(M + 1, false));
        s = "*" + s;
        p = "*" + p;
        for (int i = 0; i <= N; i += 2) {
            if (p[i] == '*')
                dp[i][0] = true;
            else
                break;
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if ((p[i] == s[j] || p[i] == '.') && dp[i - 1][j - 1])
                    dp[i][j] = true;
                if (p[i] == '*') {
                    if (dp[i - 2][j] == true)
                        dp[i][j] = true;
                    else {
                        for (int k = j; k > 0 && (s[k] == p[i - 1] || p[i - 1] == '.'); k--) {
                            if (dp[i - 2][k - 1]) {
                                dp[i][j] = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
        return dp[N][M];
    }
};