#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;
        while (true) {
            res.emplace_back(nums);
            int i, j, tmp;
            for (i = int(nums.size()) - 2; i >= 0 && nums[i] > nums[i + 1]; i--);
            if (i < 0)
                break;
            for (j = i + 1; j < int(nums.size()) && nums[j] > nums[i]; j++);
            tmp = nums[i];
            nums[i] = nums[j - 1];
            nums[j - 1] = tmp;
            for (i = i + 1, j = int(nums.size()) - 1; i < j; i++, j--) {
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
        return res;
    }
};