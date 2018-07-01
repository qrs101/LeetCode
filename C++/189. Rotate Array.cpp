#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        auto n = int(nums.size());
        if (n == 0)
            return;
        k = n - k % n;
        vector<int> tmp (nums.begin(), nums.begin() + k);
        for (int i = k; i < n; i++)
            nums[i - k] = nums[i];
        for (int i = 1; i <= k; i++)
            nums[n - i] = tmp[k - i];
    }
};