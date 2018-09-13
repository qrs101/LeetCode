#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        res.push_back(std::vector<int>());
        for (int i = 1; i <= nums.size(); i++) {
            std::vector<std::vector<int>> tmp = helper(nums, i);
            res.insert(res.end(), tmp.begin(), tmp.end());
        }
        return res;
    }

    std::vector<std::vector<int>> helper(std::vector<int> nums, int k) {
        std::vector<std::vector<int>> res;
        if (nums.size() == k) {
            res.emplace_back(nums);
            return res;
        }
        std::vector<int> nums_(nums.begin() + 1, nums.end());
        res = helper(nums_, k);
        if (k - 1 > 0) {
            std::vector<std::vector<int>> tmp = helper(nums_, k - 1);
            for (auto &i : tmp)
                i.insert(i.begin(), nums[0]);
            res.insert(res.end(), tmp.begin(), tmp.end());
        } else {
            res.emplace_back(std::vector<int>{nums[0]});
        }
        return res;
    }
};