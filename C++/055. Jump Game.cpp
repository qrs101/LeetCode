#include <iostream>
#include <vector>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int loc = 0;
        while (loc < int(nums.size())) {
            if (loc + nums[loc] >= int(nums.size()) - 1)
                return true;
            if (nums[loc] == 0)
                return false;
            int tmp_max = 0, next_loc = loc;
            for (int i = loc + 1; i <= loc + nums[loc]; i++) {
                if (tmp_max < i + nums[i]) {
                    next_loc = i;
                    tmp_max = i + nums[i];
                }
            }
            loc = next_loc;
        }
        return true;
    }
};