#include <iostream>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int i = -1;
        for (int j = 0, num = 1; j < int(nums.size()); num = 1) {
            for (j++; j < int(nums.size()) && nums[j] == nums[j - 1]; j++, num++);
            if (num == 1) {
                nums[++i] = nums[j - 1];
            } else {
                nums[++i] = nums[j - 1];
                nums[++i] = nums[j - 1];
            }
        }
        return i + 1;
    }
};