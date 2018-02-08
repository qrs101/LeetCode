#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        ans.push_back(nums);
        auto n = int(nums.size());

        while (true) {
            int i, j, tmp;
            for (i = n - 1; i > 0 && nums[i - 1] >= nums[i]; i--);
            if (i == 0)
                break;
            for (j = i; j < n && nums[j] > nums[i - 1]; j++);
            tmp = nums[i - 1];
            nums[i - 1] = nums[j - 1];
            nums[j - 1] = tmp;
            for (j = n - 1; i < j; i++, j--) {
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
            ans.push_back(nums);
        }

        return ans;
    }
};

int main() {
    vector<int> nums {1,1,2,2,3};
    Solution so;
    vector<vector<int>> ans = so.permuteUnique(nums);
    for (auto i : ans) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}