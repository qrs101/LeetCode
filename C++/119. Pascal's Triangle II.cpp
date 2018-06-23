#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        if (rowIndex < 0)
            return ans;
        ans.push_back(1);
        for (int i = 1; i <= rowIndex; i++) {
            vector<int> tmp {1};
            for (int j = 0; j < i - 1; j++)
                tmp.push_back(ans[j] + ans[j + 1]);
            tmp.push_back(1);
            ans = tmp;
        }
        return ans;
    }
};