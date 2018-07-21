#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0, Max = INT32_MAX;
        for (int k = 0; k < int(nums.size());) {
            for (int i = k + 1, j = int(nums.size()) - 1; i < j;) {
                int cur = nums[i] + nums[j] + nums[k];
                if (cur == target)
                    return target;
                else if (cur < target)
                    for (i++; i < j && nums[i] == nums[i - 1]; i++);
                else
                    for (j--; i < j && nums[j] == nums[j + 1]; j--);

                if (abs(cur - target) < Max) {
                    Max = abs(cur - target);
                    res = cur;
                }
            }
            for (k++; k < int(nums.size()) && nums[k] == nums[k - 1]; k++);
        }
        return res;
    }
};