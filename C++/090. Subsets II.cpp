#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res{vector<int>{}};
        sort(nums.begin(), nums.end());
        for (int i = 1; i <= int(nums.size()); i++) {
            vector<vector<int>> tmp = findSubsetsWithLengthK(nums, i);
            res.insert(res.end(), tmp.begin(), tmp.end());
        }
        return res;
    }

    vector<vector<int>> findSubsetsWithLengthK(vector<int> nums, int k) {
        vector<vector<int>> res;
        if (nums.size() < k)
            return res;
        if (nums.size() == k) {
            res.emplace_back(nums);
            return res;
        }
        int loc = 1;
        for (; loc < nums.size() && nums[loc] == nums[loc - 1]; loc++);
        vector<int> _nums(nums.begin() + loc, nums.end());
        for (int i = 0; i <= loc; i++) {
            vector<vector<int>> tmp = findSubsetsWithLengthK(_nums, k - i);
            if (tmp.size() == 0)
                continue;
            for (auto &subset : tmp) {
                for (int j = 0; j < i; j++)
                    subset.insert(subset.begin(), nums[0]);
            }
            res.insert(res.end(), tmp.begin(), tmp.end());
        }
        return res;
    }
};