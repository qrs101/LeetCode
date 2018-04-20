#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 1;
        auto n = int(nums.size());
        if (n == 0)
            return 0;
        for (int i = 1, len = 1; i < n; i++) {
            if (nums[i] > nums[i - 1])
                len++;
            else
                len = 1;
            if (ans < len)
                ans = len;
        }
        return ans;
    }
};