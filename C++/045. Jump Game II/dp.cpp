#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 0;
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] >= j - i) {
                    dp[i][j] = 1;
                    continue;
                }
                for (int k = i + 1; k < j; k++) {
                    if (dp[i][k] == INT_MAX || dp[k][j] == INT_MAX)
                        continue;
                    int tmp = dp[i][k] + dp[k][j];
                    if (dp[i][j] > tmp)
                        dp[i][j] = tmp;
                    if (dp[k][j] == j - k && k - i >= nums[i])
                       break;
                }
            }
        }
        return dp[0][n - 1];
    }
};

int main() {
    vector<int> a {1,2,1,1,1};
    Solution so;
    int ans = so.jump(a);
    cout << ans << endl;
    return 0;
}

