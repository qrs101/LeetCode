#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> res;
        std::sort(nums.begin(), nums.end());
        for (int k = 0; k < int(nums.size()); ) {
            for (int l = k + 1; l < int(nums.size()); ) {
                for (int i = l + 1, j = int(nums.size()) - 1; i < j; ) {
                    if (nums[k] + nums[l] + nums[i] + nums[j] == target) {
                        res.push_back(std::vector<int>{nums[k], nums[l], nums[i], nums[j]});
                        for (i++; i < j && nums[i] == nums[i - 1]; i++);
                        for (j--; i < j && nums[j] == nums[j + 1]; j--);
                    } else if (nums[k] + nums[l] + nums[i] + nums[j] < target) {
                        for (i++; i < j && nums[i] == nums[i - 1]; i++);
                    } else {
                        for (j--; i < j && nums[j] == nums[j + 1]; j--);
                    }
                }
                for (l++; l < int(nums.size()) && nums[l] == nums[l - 1]; l++);
            }
            for (k++; k < int(nums.size()) && nums[k] == nums[k - 1]; k++);
        }
        return res;
    }
};