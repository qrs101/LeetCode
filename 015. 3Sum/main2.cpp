#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < nums.size()) {
            int target = -nums[i];
            int start = i + 1;
            int end = nums.size() - 1;
            while (start < end) {
                if (nums[start] + nums[end] < target)
                    start++;
                else if (nums[start] + nums[end] > target)
                    end--;
                else {
                    vector<int> tmp {nums[i], nums[start], nums[end]};
                    res.push_back(tmp);
                    start++;
                    end--;
                    while (start < end && nums[start] == nums[start - 1])
                        start++;
                    while (start < end && nums[end] == nums[end + 1])
                        end--;
                }
            }
            i++;
            while (i < nums.size() && nums[i] == nums[i - 1])
                i++;
        }
        return res;
    }
};

int main() {
    Solution so;
    vector<int> nums {-1,2,2,-3,4,-2,-2,1,0,1,1,0,0};
    vector<vector<int>> res = so.threeSum(nums);
    for (auto i : res) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}