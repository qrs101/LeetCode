#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        auto n = int(nums.size());
        if (n == 0)
            return 0;
        vector<int> dp (n, nums[0]);
        int ans = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i] = nums[i];
            if (dp[i - 1] > 0)
                dp[i] += dp[i - 1];
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};