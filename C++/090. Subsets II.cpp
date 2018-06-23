#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i <= int(nums.size()); i++) {
            vector<vector<int>> tmp = findk(nums, i);
            ans.insert(ans.end(), tmp.begin(), tmp.end());
        }
        return ans;
    }

    vector<vector<int>> findk(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        if (k == 0) {
            ans.push_back(vector<int>());
            return ans;
        }
        if (k > nums.size())
            return ans;
        if (k == nums.size()) {
            ans.push_back(nums);
            return ans;
        }
        if (k == 1) {
            if (nums.size() >= 1)
                ans.push_back(vector<int>(1, nums[0]));
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] != nums[i - 1])
                    ans.push_back(vector<int>(1, nums[i]));
            }
            return ans;
        }
        vector<int> num(nums);
        int t = 1;
        for (int i = int(num.size()) - 2; i >= 0 && num[i] == num[num.size() - 1]; i--) {
            t++;
            num.erase(num.end() - 1);
        }
        int n = num[num.size() - 1];
        num.erase(num.end() - 1);
        for (int i = 0; i <= t; i++) {
            vector<vector<int>> tmp = findk(num, k - i);
            for (auto& j : tmp) {
                for (int h = 0; h < i; h++)
                    j.push_back(n);
            }
            ans.insert(ans.end(), tmp.begin(), tmp.end());
            if (k - i == 0)
                break;
        }
        return ans;
    }
};

int main() {
    vector<int> nums {1,2,2};
    Solution so;
    vector<vector<int>> ans = so.findk(nums, 3);
    for (auto i : ans) {
        for (auto j : i)
            cout << j << " ";
        cout << "#" << endl;
    }
    return 0;
}