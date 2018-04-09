#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if (numRows < 1)
            return ans;
        ans.push_back(vector<int>(1, 1));
        for (int i = 1; i < numRows; i++) {
            vector<int> tmp {1};
            for (int j = 0; j < i - 1; j++)
                tmp.push_back(ans[i - 1][j] + ans[i - 1][j + 1]);
            tmp.push_back(1);
            ans.push_back(tmp);
        }
        return ans;
    }
};