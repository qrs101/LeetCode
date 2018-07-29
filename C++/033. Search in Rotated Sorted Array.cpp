#include <iostream>
#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int i = 0, j = int(nums.size()) - 1;
        while (i <= j) {
            int m = (i + j) / 2;
            if (nums[m] == target)
                return m;
            if (nums[i] > nums[m] && (nums[i] <= target || target < nums[m]))
                j = m - 1;
            else if (nums[i] < nums[m] && nums[i] <= target && target < nums[m])
                j = m - 1;
            else
                i = m + 1;
        }
        return -1;
    }
};