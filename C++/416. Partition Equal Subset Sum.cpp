#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = int(nums.size());
        for (auto i : nums)
            sum += i;
        if (sum % 2 == 1)
            return false;
        sum /= 2;
        nums.insert(nums.begin(), 0);
        vector<bool> dp (sum + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = sum; j >= nums[i]; j--) {
                dp[j] = (dp[j] || dp[j - nums[i]]);
            }
        }
        return dp[sum];
        /*  2维解法
        int sum = 0;
        int n = int(nums.size());
        for (auto i : nums)
            sum += i;
        if (sum % 2 == 1)
            return false;
        sum /= 2;
        nums.insert(nums.begin(), 0);
        vector<vector<bool>> dp (n + 1, vector<bool>(sum + 1, false));
        for (int i = 0; i <= n; i++)
            dp[i][0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = sum; j >= 1; j--) {
                if (nums[i] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - nums[i]]);
            }
        }
        return dp[n][sum];
        */
    }
};

int main() {
    Solution so;
    vector<int> nums {1,5,11,3};
    bool ans = so.canPartition(nums);
    cout << ans << endl;
}