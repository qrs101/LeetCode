#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        if (n <= 0 || k <= 0 || k > n)
            return ans;
        if (k == 1) {
            for (int i = 1; i <= n; i++)
                ans.push_back(vector<int>(1, i));
            return ans;
        }
        if (n == k) {
            vector<int> tmp;
            for (int i = 1; i <= n; i++)
                tmp.push_back(i);
            ans.push_back(tmp);
            return ans;
        }
        ans = combine(n - 1, k);
        vector<vector<int>> tmp = combine(n - 1, k - 1);
        for (auto& i : tmp) {
            i.push_back(n);
            ans.push_back(i);
        }
        return ans;
    }
};