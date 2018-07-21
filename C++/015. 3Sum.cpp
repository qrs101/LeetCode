#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < int(nums.size());) {
            if (nums[k] > 0)
                break;
            for (int i = k + 1, j = int(nums.size()) - 1; i < j;) {
                if (nums[i] + nums[j] == -nums[k]) {
                    std::vector<int> tmp {nums[k], nums[i], nums[j]};
                    res.push_back(tmp);
                    for (i++; i < j && nums[i] == nums[i - 1]; i++);
                    for (j--; i < j && nums[j] == nums[j + 1]; j--);
                } else if (nums[i] + nums[j] < -nums[k]) {
                    for (i++; i < j && nums[i] == nums[i - 1]; i++);
                } else {
                    for (j--; i < j && nums[j] == nums[j + 1]; j--);
                }
            }
            for (k++; k < int(nums.size()) && nums[k] == nums[k - 1]; k++);
        }
        return res;
    }
};