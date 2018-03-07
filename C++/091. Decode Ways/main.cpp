#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0 || s[0] == '0')
            return 0;
        int m = int(s.size());
        vector<int> dp (m + 1, 1);
        s = '#' + s;
        for (int i = 2; i <= m; i++) {
            if (s[i] == '0') {
                if (s[i - 1] == '0' || s[i - 1] > '2')
                    return 0;
                else
                    dp[i] = dp[i - 2];
            } else if (s[i - 1] == '0' || s[i - 1] > '2' || (s[i - 1] == '2' && s[i] > '6'))
                dp[i] = dp[i - 1];
            else
                dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[m];
    }
};