#include <iostream>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (int(nums.size()) == 0)
            return 0;
        int i = 1;
        for (int j = 1; j < int(nums.size()); j++) {
            if (nums[j] != nums[j - 1]) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};