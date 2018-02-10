#include <iostream>
#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = INT_MIN;
        int sum = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (max < nums[i])
                max = nums[i];
            if (nums[i] <= 0)
                continue;
            for (int j = i, tmp = 0; j < nums.size(); j++) {
                tmp = tmp + nums[j];
                if (sum < tmp)
                    sum = tmp;
            }
        }
        if (max <= 0)
            return max;
        return sum;
    }
};

