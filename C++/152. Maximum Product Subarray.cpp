#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /*
    int maxProduct(vector<int>& nums) {
        auto n = int(nums.size());
        if (n == 0)
            return 0;
        vector<int> Max(n, nums[0]);
        vector<int> Min(n, nums[0]);
        int res = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] == 0) {
                Max[i] = 1;
                Min[i] = 1;
                if (res < 0)
                    res = 0;
            } else if (nums[i] > 0) {
                if (Min[i - 1] > 0) {
                    Max[i] = Max[i - 1] * nums[i];
                    Min[i] = nums[i];
                } else if (Max[i - 1] > 0) {
                    Max[i] = Max[i - 1] * nums[i];
                    Min[i] = Min[i - 1] * nums[i];
                } else {
                    Max[i] = nums[i];
                    Min[i] = Min[i - 1] * nums[i];
                }
                if (res < Max[i])
                    res = Max[i];
            } else {
                if (Min[i - 1] > 0) {
                    Max[i] = nums[i];
                    Min[i] = Max[i - 1] * nums[i];
                } else if (Max[i - 1] > 0) {
                    Max[i] = Min[i - 1] * nums[i];
                    Min[i] = Max[i - 1] * nums[i];
                } else {
                    Max[i] = Min[i - 1] * nums[i];
                    Min[i] = nums[i];
                }
                if (res < Max[i])
                    res = Max[i];
            }
        }
        return res;
    }
     */
    int maxProduct(vector<int>& nums) {
        auto n = int(nums.size());
        if (n == 0)
            return 0;
        int res = nums[0];
        for (int i = 1, Max = nums[0], Min = nums[0]; i < n; i++) {
            if (nums[i] < 0) {
                int tmp = Max;
                Max = Min;
                Min = tmp;
            }

            Max = max(Max * nums[i], nums[i]);
            Min = min(Min * nums[i], nums[i]);

            res = max(res, Max);
        }
        return res;
    }
};