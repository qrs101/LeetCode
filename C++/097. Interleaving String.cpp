#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        auto m = int(s1.size());
        auto n = int(s2.size());
        if (m + n != s3.size())
            return false;
        string str1 = '#' + s1;
        string str2 = '#' + s2;
        string str3 = '#' + s3;
        vector<vector<bool>> dp (m + 1, vector<bool>(n + 1, false));
        for (int k = 0; k <= n; k++)
            if (str2.substr(1, k) == str3.substr(1, k))
                dp[0][k] = true;
        for (int k = 1; k <= m; k++)
            if (str1.substr(1, k) == str3.substr(1, k))
                dp[k][0] = true;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (dp[i][j - 1] && str2[j] == str3[i + j])
                    dp[i][j] = true;
                else if (dp[i - 1][j] && str1[i] == str3[i + j])
                    dp[i][j] = true;
            }
        }
        return dp[m][n];
    }
};