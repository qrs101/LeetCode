#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int m;
        int i = 0;
        int j = int(nums.size()) - 1;
        vector<int> ans {-1, -1};
        if (j == -1 || target < nums[i] || target > nums[j])
            return ans;
        else if (target == nums[i])
            ans[0] = i;
        else {
            while (j - i > 1) {
                m = (i + j) / 2;
                if (nums[m] >= target)
                    j = m;
                else
                    i = m;
            }
            if (nums[i] != target && nums[j] == target)
                ans[0] = j;
        }

        i = 0;
        j = int(nums.size()) - 1;
        if (target == nums[j])
            ans[1] = j;
        else {
            while (j - i > 1) {
                m = (i + j) / 2;
                if (nums[m] <= target)
                    i = m;
                else
                    j = m;
            }
            if (nums[i] == target && nums[j] != target)
                ans[1] = i;
        }

        return ans;
    }
};

int main() {
    vector<int> nums {0};
    Solution so;
    vector<int> ans = so.searchRange(nums, 0);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}