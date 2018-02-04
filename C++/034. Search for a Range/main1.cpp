#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int m;
        int i = 0;
        int j = int(nums.size()) - 1;
        vector<int> ans;
        while (i <= j) {
            m = (i + j) / 2;
            if (nums[m] == target) {
                for (i = m - 1; i >= 0 && nums[i] == target; i--);
                for (j = m + 1; j < int(nums.size()) && nums[j] == target; j++);
                ans.push_back(i + 1);
                ans.push_back(j - 1);
                return ans;
            }
            else if (nums[m] < target)
                i = m + 1;
            else
                j = m - 1;
        }

        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }
};

int main() {
    vector<int> nums {0,0,0,0,0,0};
    Solution so;
    vector<int> ans = so.searchRange(nums, 0);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}