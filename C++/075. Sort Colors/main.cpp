#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i, j, k;
        for (i = 0; i < nums.size() && nums[i] == 0; i++);
        for (j = i; j < nums.size() && nums[j] == 1; j++);
        for (k = int(nums.size()) - 1; k >= j && nums[k] == 2; k--);
        while (j <= k) {
            if (nums[j] == 1)
                j++;
            else if (nums[j] == 0) {
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
                i++;
                j++;
            } else if (nums[j] == 2) {
                int tmp = nums[j];
                nums[j] = nums[k];
                nums[k] = tmp;
                k--;
            }
        }
    }
};