#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        auto n = int(s.size());
        int start = 0, end = 0;
        vector<vector<bool>> dp (unsigned(n), vector<bool>(unsigned(n), true));
        for (int j = 0; j < n; j++) {
            for (int i = j - 1; i >= 0; i--) {
                dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
                if (dp[i][j] && end - start < j - i) {
                    start = i;
                    end   = j;
                }
            }
        }
        return s.substr(unsigned(start), unsigned(end - start + 1));
    }
};