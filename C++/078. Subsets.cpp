#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back(vector<int>());
        for (int i = 1; i <= nums.size(); i++) {
            vector<vector<int>> tmp = findk(nums, i);
            ans.insert(ans.end(), tmp.begin(), tmp.end());
        }
        return ans;
    }

    vector<vector<int>> findk(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        if (k == 1) {
            for (auto i : nums)
                ans.push_back(vector<int>(1, i));
            return ans;
        }
        if (k == nums.size()) {
            ans.push_back(nums);
            return ans;
        }
        vector<int> tmp(nums);
        tmp.erase(tmp.end() - 1);
        ans = findk(tmp, k);
        vector<vector<int>> t = findk(tmp, k - 1);
        int h = nums[nums.size() - 1];
        for (auto& i : t) {
            i.push_back(h);
            ans.push_back(i);
        }
        return ans;
    }
};