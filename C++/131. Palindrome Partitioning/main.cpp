#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        auto n = int(s.size());
        s = '#' + s;
        vector<vector<vector<string>>> ans (n + 1, vector<vector<string>>());
        ans[0].push_back(vector<string>());
        vector<vector<bool>> dp (n + 2, vector<bool>(n + 2, true));
        for (int j = 1; j <= n; j++) {
            for (int i = j; i > 0; i--) {
                if (!(s[i] == s[j] && dp[i + 1][j - 1])) {
                    dp[i][j] = false;
                    continue;
                }
                for (auto k : ans[i - 1]) {
                    vector<string> tmp(k);
                    tmp.push_back(s.substr(i, j - i + 1));
                    ans[j].push_back(tmp);
                }
            }
        }
        return ans[n];
    }
};

int main() {
    Solution so;
    vector<vector<string>> ans = so.partition("aab");
    for (auto i : ans) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}