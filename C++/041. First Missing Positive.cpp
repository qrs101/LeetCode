#include <iostream>
#include <vector>

class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        for (int i = 0; i < int(nums.size()); i++) {
            int tmp = nums[i];
            if (tmp > 0 && tmp <= int(nums.size()) && tmp != nums[tmp - 1]) {
                nums[i] = nums[tmp - 1];
                nums[tmp - 1] = tmp;
                i--;
            }
        }

        for (int i = 0; i < int(nums.size()); i++) {
            if (nums[i] != i + 1)
                return i + 1;
        }

        return int(nums.size()) + 1;
    }
};