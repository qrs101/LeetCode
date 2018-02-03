该题的思路是用动态规划，dp[i]表示以s[i]结尾的最长有效长度。S是一个栈
```
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
    }
}
```