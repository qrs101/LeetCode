#include <iostream>
#include <vector>

class Solution {
public:
    bool search(std::vector<int>& nums, int target) {
        if (nums.size() == 0)
            return false;
        for (int i = 0, j = int(nums.size()) - 1; i <= j;) {
            int m = (i + j) / 2;
            if (nums[m] == target)
                return true;
            if (nums[m] > nums[i]) {
                if (nums[i] <= target && target < nums[m])
                    j = m - 1;
                else
                    i = m + 1;
            } else if (nums[m] < nums[i]) {
                if (nums[m] < target && target <= nums[j])
                    i = m + 1;
                else
                    j = m - 1;
            } else {
                i++;
            }
        }
        return false;
    }
};