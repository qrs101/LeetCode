#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[nums.size() - 1];
        for (int k = 0; k < nums.size() - 2; k++) {
            int i = k + 1;
            int j = nums.size() - 1;
            while (i < j) {
                int tmp = nums[k] + nums[i] + nums[j];
                if (tmp < target)
                    i++;
                else if (tmp > target)
                    j--;
                else
                    return target;
                if (abs(tmp - target) < abs(ans - target))
                    ans = tmp;
            }
        }

        return ans;
    }
};

int main() {
    Solution so;
    vector<int> nums {-1,2,1,4};
    int res = so.threeSumClosest(nums, 1);
    cout << res << endl;
    return 0;
}