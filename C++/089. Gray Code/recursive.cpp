#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        if (n == 0) {
            ans.push_back(0);
            return ans;
        }
        ans = grayCode(n - 1);
        int t = 1;
        for (int i = 1; i < n; i++)
            t <<= 1;
        int m = int(ans.size());
        for (int i = m - 1; i >= 0; i--) {
            ans.push_back(ans[i] + t);
        }
        return ans;
    }
};