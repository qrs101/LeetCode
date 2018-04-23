#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        auto n = int(nums.size());
        int ans = nums[0];
        for (int i = 1; i < n; i++) {
            ans = ans ^ nums[i];
        }
        return ans;
    }
};