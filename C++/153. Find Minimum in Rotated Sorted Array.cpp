#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        auto n = int(nums.size());
        int i = 0, j = n - 1;
        while (i < j) {
            if (nums[i] < nums[j])
                return nums[i];
            int m = (i + j) / 2;

            if (nums[m] >= nums[0])
                i = m + 1;
            else
                j = m;
        }

        return nums[i];
    }
};