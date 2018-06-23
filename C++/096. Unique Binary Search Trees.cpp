#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp (n + 1, 1);
        for (int i = 2; i <= n; i++) {
            int s = 0;
            for (int j = 1; j <= i; j++)
                s += dp[j - 1] * dp[i - j];
            dp[i] = s;
        }
        return dp[n];
    }
};