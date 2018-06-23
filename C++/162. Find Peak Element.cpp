#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        auto n = int(nums.size());
        if (n == 1)
            return 0;
        if (nums[0] > nums[1])
            return 0;
        if (nums[n - 2] < nums[n - 1])
            return n - 1;

        int i = 0, j = n - 1;
        while (i < j) {
            int m = (i + j) / 2;
            if ((m == 0 || nums[m] > nums[m - 1]) && (m == n - 1 || nums[m] > nums[m + 1]))
                return m;
            else if (m == 0 || nums[m] > nums[m - 1])
                i = m;
            else
                j = m;
        }
    }
};