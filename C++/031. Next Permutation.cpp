#include <iostream>
#include <vector>

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int i, j;
        for (i = int(nums.size()) - 2; i >= 0 && nums[i] >= nums[i + 1]; i--);
        if (i == -1) {
            reverseOrder(nums, 0, int(nums.size()) - 1);
            return;
        }
        for (j = i + 1; j < int(nums.size()) && nums[j] > nums[i]; j++);
        int tmp = nums[j - 1];
        nums[j - 1] = nums[i];
        nums[i] = tmp;
        reverseOrder(nums, i + 1, int(nums.size()) - 1);
    }

    void reverseOrder(std::vector<int>& nums, int i, int j) {
        for (; i < j; i++, j--) {
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
    }
};