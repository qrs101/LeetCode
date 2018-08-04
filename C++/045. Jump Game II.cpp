#include <iostream>
#include <vector>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        int loc = 0, res = 0;
        while (loc < int(nums.size())) {
            if (loc == int(nums.size()) - 1)
                return res;
            else if (loc + nums[loc] >= int(nums.size()) - 1)
                return res + 1;
            int next_loc = loc;
            for (int i = loc + 1, tmp_max = 0; i <= loc + nums[loc]; i++) {
                if (tmp_max < i + nums[i]) {
                    tmp_max = i + nums[i];
                    next_loc = i;
                }
            }
            loc = next_loc;
            res++;
        }
        return res;
    }
};