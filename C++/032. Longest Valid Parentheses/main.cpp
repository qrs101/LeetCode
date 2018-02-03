#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string str) {
        stack<char> S;
        string s = "#" + str;
        vector<int> dp (s.size(), 0);
        int ans = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '(')
                S.push('(');
            else if (!S.empty()) {
                S.pop();
                if (s[i - 1] == '(')
                    dp[i] = 2;
                else
                    dp[i] = dp[i - 1] + 2;
                dp[i] = dp[i] + dp[i - dp[i]];
                if (ans < dp[i])
                    ans = dp[i];
            }
        }
        return ans;
    }
};

int main() {
    Solution so;
    int ans = so.longestValidParentheses("()(())");
    cout << ans << endl;
}