#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_set<int> S {};
        unordered_map<int, bool> M;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (S.find(nums[i]) != S.end())
                continue;
            int target = -nums[i];
            for (int j = i + 1; j < n; j++) {
                if (S.find(nums[j]) != S.end())
                    continue;
                int tmp = target - nums[j];
                if (M.find(tmp) != M.end() && M[tmp] == false) {
                    vector<int> v {nums[i], nums[j], tmp};
                    res.push_back(v);
                    M[tmp] = true;
                    M.insert(unordered_map<int, bool>::value_type(nums[j], true));
                } else if (M.find(nums[j]) == M.end()) {
                    M.insert(unordered_map<int, bool>::value_type(nums[j], false));
                }
            }
            S.insert(nums[i]);
            M.clear();
        }
        return res;
    }
};

int main() {
    Solution so;
    vector<int> nums {1,1};
    vector<vector<int>> res = so.threeSum(nums);
    for (auto i : res) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}