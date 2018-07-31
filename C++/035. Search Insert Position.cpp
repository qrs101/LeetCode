#include <iostream>
#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int i = 0, j = int(nums.size()) - 1;
        while (i <= j) {
            int m = (i + j) / 2;
            if (nums[m] == target)
                return m;
            else if (nums[m] > target)
                j = m - 1;
            else
                i = m + 1;
        }
        if (i == int(nums.size()) || nums[i] > target)
            return i;
        else
            return i + 1;
    }
};