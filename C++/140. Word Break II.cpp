#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> S (wordDict.begin(), wordDict.end());
        auto n = int(s.size());
        vector<bool> dp (n + 1, false);
        dp[0] = true;
        s = '#' + s;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j > 0; j--) {
                string tmp = s.substr(j, i - j + 1);
                if (dp[j - 1] == true && S.find(tmp) != S.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        vector<string> ans;
        if (!dp[n])
            return ans;
        ans = helper(s, n, dp, S);
        return ans;
    }

    vector<string> helper(string s, int n, vector<bool>& dp, set<string>& S) {
        vector<string> ans;
        for (int i = n; i > 0; i--) {
            string str = s.substr(i, n - i + 1);
            if (dp[i - 1] && S.find(str) != S.end()) {
                if (i == 1) {
                    ans.push_back(s.substr(1, n));
                    break;
                }
                vector<string> tmp = helper(s, i - 1, dp, S);
                for (auto& i : tmp) {
                    i = i + " " + str;
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<string> a {"abad", "fbvd", "dsaf"};
    set<string> S (a.begin(), a.end());
    for (auto i : S)
        cout << i << " ";
}