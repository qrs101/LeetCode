#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        std::vector<int> res {-1, -1};
        if (nums.size() == 0)
            return res;
        int i = 0;
        int j = int(nums.size()) - 1;
        if (nums[i] == target)
            res[0] = i;
        else {
            while (j - i > 1) {
                int m = (i + j) / 2;
                if (nums[m] >= target)
                    j = m;
                else
                    i = m;
            }
            if (nums[j] == target && nums[i] != target)
                res[0] = j;    
        }
        
        i = 0;
        j = int(nums.size()) - 1;
        if (nums[j] == target)
            res[1] = j;
        else {
            while (j - i > 1) {
                int m = (i + j) / 2;
                if (nums[m] <= target)
                    i = m;
                else
                    j = m;
            }
            if (nums[i] == target && nums[j] != target)
                res[1] = i;
        }

        return res;
    }
};