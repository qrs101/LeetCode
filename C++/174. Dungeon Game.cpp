#include<iostream>
#include<vector>
#include<climit>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = int(dungeon.size());
        int n = int(dungeon[0].size());
        vector<vector<long>> dp (m + 1, vector<long>(n + 1, INT_MAX));
        dp[m][n - 1] = 1;
        dp[m - 1][n] = 1;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                long t1 = long(dp[i + 1][j]) - long(dungeon[i][j]);
                long t2 = long(dp[i][j + 1]) - long(dungeon[i][j]);
                dp[i][j] = max(min(t1, t2), long(1));
            }
        }
        return int(dp[0][0]);
    }
};