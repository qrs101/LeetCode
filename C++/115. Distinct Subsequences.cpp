#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        auto m = int(s.size());
        auto n = int(t.size());
        s = '#' + s;
        t = '#' + t;
        vector<vector<int>> dp (m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; dp[i][0] = 1, i++);
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i < j)
                    continue;
                if (s[i] == t[j])
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[m][n];
    }
};

int main() {
    string s = "a";
    string t = "b";
    Solution so;
    int ans = so.numDistinct(s, t);
    cout << ans << endl;
}