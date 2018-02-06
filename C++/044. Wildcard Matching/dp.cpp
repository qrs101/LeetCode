#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        string str = "#" + s;
        string pat = "#" + p;
        int m = int(pat.size());
        int n = int(str.size());
        vector<vector<bool>> dp(m, vector<bool>(n, false));
        dp[0][0] = true;
        for (int i = 1; i < m; i++) {
            if (pat[i] == '*' && dp[i - 1][0] == true)
                dp[i][0] = true;
            for (int j = 1; j < n; j++) {
                if (pat[i] == '*') {
                    for (int k = 0; k <= j; k++) {
                        if (dp[i - 1][k] == true) {
                            dp[i][j] = true;
                            break;
                        }
                    }
                }
                else if (dp[i - 1][j - 1] && (pat[i] == '?' || pat[i] == str[j]))
                    dp[i][j] = true;
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
    Solution so;
    bool ans = so.isMatch("aaab", "c*a*b");
    cout << ans << endl;
    return 0;
}