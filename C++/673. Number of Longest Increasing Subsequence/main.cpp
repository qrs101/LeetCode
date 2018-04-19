#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        auto n = int(nums.size());
        vector<int> Len (n, 1);
        vector<int> Num (n, 1);
        int max_len = 1;
        for (int i = 1; i < n; i++) {
            int tmp_len = 1;
            for (int j = 0; j < i; j++)
                if (nums[j] < nums[i] && tmp_len < Len[j] + 1)
                    tmp_len = Len[j] + 1;
            Len[i] = tmp_len;
            int tmp_num = 0;
            bool got = false;
            for (int j = 0; j < i; j++)
                if (nums[j] < nums[i] && Len[j] == tmp_len - 1) {
                    tmp_num += Num[j];
                    got = true;
                }
            if (got)
                Num[i] = tmp_num;
            if (max_len < Len[i])
                max_len = Len[i];
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (Len[i] == max_len)
                ans += Num[i];
        return ans;
    }
};