#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<int> v (nums);
        vector<vector<int>> res;
        if (v.size() < 4)
            return res;

        sort(v.begin(), v.end());
        for (int k = 0; k < v.size() - 3; k++) {
            if (v[k] + v[k + 1] + v[k + 2] + v[k + 2] > target)
                break;
            if (v[k] + v[v.size() - 3] + v[v.size() - 2] + v[v.size() - 1] < target)
                continue;
            int target_ = target - v[k];
            for (int l = k + 1; l < v.size() - 2; l++) {
                if (v[l] + v[l + 1] + v[l + 2] > target_)
                    break;
                if (v[l] + v[v.size() - 2] + v[v.size() - 1] < target_)
                    continue;
                int target__ = target_ - v[l];
                int i = l + 1;
                int j = v.size() - 1;
                while (i < j) {
                    int tmp = v[i] + v[j];
                    if (tmp < target__)
                        i++;
                    else if (tmp > target__)
                        j--;
                    else {
                        vector<int> a {v[k], v[l], v[i], v[j]};
                        res.push_back(a);
                        do {
                            i++;
                        }
                        while (i < j && v[i] == v[i - 1]);
                        do {
                            j--;
                        }
                        while (i < j && v[j] == v[j + 1]);
                    }
                }
                while (l < v.size() - 3 && v[l] == v[l + 1])
                    l++;
            }
            while (k < v.size() - 4 && v[k] == v[k + 1])
                k++;
        }

        return res;
    }
};

int main() {
    Solution so;
    vector<int> nums {1,2};
    vector<vector<int>> res = so.fourSum(nums, 0);
    for (auto i : res) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}