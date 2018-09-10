#include <iostream>
#include <vector>

class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        int loc_0 = 0, loc_2 = int(nums.size()) - 1;
        for (int i = 0; i <= loc_2; i++) {
            if (nums[i] == 0) {
                swap(nums, loc_0, i);
                loc_0++;
            } else if (nums[i] == 2) {
                swap(nums, loc_2, i);
                i--;
                loc_2--;
            }
        }
    }

    void swap(std::vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};