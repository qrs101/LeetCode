#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 0)
            return "";
        if (n == 1)
            return strs[0];
        bool tag = true;
        int j = -1;
        while (tag) {
            j++;
            if (j >= strs[0].size())
                break;
            char tmp = strs[0][j];
            for (int i = 1; i < n; i++) {
                if (j >= strs[i].size() || strs[i][j] != tmp) {
                    tag = false;
                    break;
                }
            }
        }
        return strs[0].substr(0, j);
    }
};

int main() {
    vector<string> s {"c", "c"};
    Solution so;
    cout << so.longestCommonPrefix(s) << endl;
}