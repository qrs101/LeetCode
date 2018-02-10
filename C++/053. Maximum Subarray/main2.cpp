#include <iostream>
#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum = sum + nums[i];
            if (ans < sum)
                ans = sum;
            if (sum < 0)
                sum = 0;
        }
        return ans;
    }
};

int main() {
    vector<int> nums {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution so;
    int ans = so.maxSubArray(nums);
    cout << ans << endl;
}

