#include <iostream>
#include <vector>

class Solution {
public:
    int longestValidParentheses(std::string str) {
        str = "#" + str;
        std::vector<int> dp (str.size(), 0);
        int res = 0;
        for (int i = 1; i < int(str.size()); i++) {
            if (str[i] == ')' && str[i - 1 - dp[i - 1]] == '(')
                dp[i] = dp[i - 1] + 2 + dp[i - 2 - dp[i - 1]];
            if (res < dp[i])
                res = dp[i];
        }
        return res;
    }
};