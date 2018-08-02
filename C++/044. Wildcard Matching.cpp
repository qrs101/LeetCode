#include <iostream>
#include <vector>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        int len_p = int(p.size()), len_s = int(s.size());
        std::vector<std::vector<bool>> dp(p.size() + 1, std::vector<bool>(s.size() + 1, false));
        dp[0][0] = true;
        s = "#" + s;
        p = "#" + p;
        for (int i = 1; i <= len_p && p[i] == '*'; i++)
            dp[i][0] = true;
        for (int i = 1; i <= len_p; i++) {
            for (int j = 1; j <= len_s; j++) {
                if (dp[i - 1][j - 1] && (p[i] == '?' || p[i] == s[j]))
                    dp[i][j] = true;
                else if (p[i] == '*') {
                    for (int k = j; k >= 0; k--) {
                        if (dp[i - 1][k] == true) {
                            dp[i][j] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[len_p][len_s];
    }
};