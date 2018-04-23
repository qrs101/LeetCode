#include <istream>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
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
        return dp[n];
    }
};

int main() {
    vector<string> a {"abad", "fbvd", "dsaf"};
    set<string> S (a.begin(), a.end());
    for (auto i : S)
        cout << i << " ";
}