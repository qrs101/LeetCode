#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int ans = 0;
        for (auto str : words) {
            if (helper(S, str))
                ans++;
        }
        return ans;
    }

    bool helper(string S, string s) {
        int i = 0, j = 0, ii, jj;
        int n = int(S.size());
        int m = int(s.size());
        while (i < m && j < n) {
            if (s[i] != S[j])
                return false;
            for (ii = 0; i + ii < m && s[i + ii] == s[i]; ii++);
            for (jj = 0; j + jj < n && S[j + jj] == S[j]; jj++);
            if ((jj >= 3 && ii <= jj) || ii == jj) {
                i = i + ii;
                j = j + jj;
            } else {
                return false;
            }
        }
        if (i == m && j == n)
            return true;
        return false;
    }
};

int main() {
    Solution so;
    bool ans = so.helper("aaaa", "aa");
    cout << ans << endl;
    return 0;
}