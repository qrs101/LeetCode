#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        auto n = int(nums.size());
        int ans = 0;
        vector<int> dp (n + 1, 0);
        nums.insert(nums.begin(), 0);
        for (int i = 1; i <= n; i++) {
            dp[i] = ans + nums[i];
            if (ans < dp[i - 1])
                ans = dp[i - 1];
        }
        if (ans < dp[n])
            ans = dp[n];
        return ans;
    }
};