#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)  {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans = findSum(candidates, 0, target);
        return ans;
    }

    vector<vector<int>> findSum(vector<int>& array, int num, int target) {
        vector<vector<int>> ans;
        int n = array.size();
        if (num > n - 1)
            return ans;
        for (int i = num; i < n; i++) {
            int a = array[i];
            if (a > target)
                break;
            else if (a == target) {
                ans.push_back(vector<int> {a});
                break;
            }
            vector<vector<int>> tmp = findSum(array, i + 1, target - a);
            for (int j = 0; j < tmp.size(); j++) {
                tmp[j].insert(tmp[j].begin(), a);
                ans.push_back(tmp[j]);
            }
            while (i + 1 < n && array[i] == array[i + 1])
                i++;
        }
        return ans;
    }
};

int main() {
    vector<int> candidates {10, 1, 2, 7, 6, 1, 5};
    Solution so;
    vector<vector<int>> ans = so.combinationSum2(candidates, 8);
    for (auto i : ans) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}