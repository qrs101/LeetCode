#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        auto n = int(nums.size());
        vector<int> dp (n, 1);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] >= nums[i])
                    continue;
                if (dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;
            }
            if (ans < dp[i])
                ans = dp[i];
        }
        return ans;
    }
};