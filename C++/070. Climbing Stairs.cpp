#include <iostream>
#include <vector>

class Solution {
public:
    int climbStairs(int n) {
        std::vector<int> dp (unsigned(n + 10), 1);
        for (int i = 2; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
};