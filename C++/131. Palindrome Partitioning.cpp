#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //递归
    vector<vector<string>> partition(string s) {
        auto n = int(s.size());
        vector<vector<bool>> dp(n, vector<bool>(n, true));
        for (int j = 1; j < n; j++) {
            for (int i = j - 1; i >= 0; i--) {
                if (s[i] != s[j] || !dp[i + 1][j - 1])
                    dp[i][j] = false;
            }
        }
        vector<vector<string>> res = helper(s, 0, n, dp);
        return res;
    }

    vector<vector<string>> helper(const string &s, int loc, int len, vector<vector<bool>> &dp) {
         vector<vector<string>> res;
         for (int i = loc; i < len - 1; i++) {
             if (!dp[loc][i])
                 continue;
             vector<vector<string>> tmp = helper(s, i + 1, len, dp);
             if (tmp.size() > 0) {
                 for (auto &j : tmp) {
                     j.insert(j.begin(), s.substr(loc, i - loc + 1));
                 }
                 res.insert(res.end(), tmp.begin(), tmp.end());
             }
         }
         if (dp[loc][len - 1])
             res.emplace_back(vector<string>{s.substr(loc)});
         return res;
    }

    /**
    空间换时间
    vector<vector<string>> partition(string s) {
        auto n = int(s.size());
        s = '#' + s;
        vector<vector<vector<string>>> res (n + 1, vector<vector<string>>());
        res[0].push_back(vector<string>());
        vector<vector<bool>> dp(n + 2, vector<bool>(n + 2, true));
        for (int j = 1; j <= n; j++) {
            for (int i = j; i > 0; i--) {
                if (!(s[i] == s[j] && dp[i + 1][j - 1])) {
                    dp[i][j] = false;
                    continue;
                }
                for (auto k : res[i - 1]) {
                    vector<string> tmp(k);
                    tmp.push_back(s.substr(i, j - i + 1));
                    res[j].push_back(tmp);
                }
            }
        }
        return res[n];
    }
    **/
};