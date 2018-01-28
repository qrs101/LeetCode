#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int start = 0, end = 0;
        vector<vector<bool>> a (n, vector<bool>(n, true));
        for (int j = 1; j < n; j++) {
            int t = j;
            for (int i = 0; i < n-j; i++, t++) {
                if (s[i] != s[t])
                    a[i][t] = false;
                else {
                    if(t-i == 1 || a[i+1][t-1] == true) {
                        a[i][t] = true;
                        start = i;
                        end = t;
                    }
                    else
                        a[i][t] = false;
                }
            }
        }
        return s.substr(start, end - start + 1);
    }
};

int main() {
    string s = "cbbd";
    Solution so;
    string ans = so.longestPalindrome(s);
    cout << ans << endl;
    return 0;
}