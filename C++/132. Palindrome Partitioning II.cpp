#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        auto n = int(s.size());
        if (n == 0)
            return 0;
        s = '#' + s;
        vector<int> ans (n + 1, -1);
        vector<vector<bool>> dp (n + 2, vector<bool>(n + 2, true));
        for (int j = 1; j <= n; j++) {
            ans[j] = ans[j - 1] + 1;
            for (int i = j - 1; i > 0; i--) {
                if (!(s[i] == s[j] && dp[i + 1][j - 1])) {
                    dp[i][j] = false;
                    continue;
                }
                if (ans[i - 1] + 1 < ans[j])
                    ans[j] = ans[i - 1] + 1;
            }
        }
        return ans[n];
    }
};

int main() {
    Solution so;
    int ans = so.minCut("aab");
    cout << ans << endl;
}