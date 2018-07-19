func longestValidParentheses(s string) int {
	s = "#" + s
	dp := make([]int, len(s), len(s))
	res := 0
	for i := 1; i < len(s); i++ {
		if s[i] == ')' && s[i - 1 - dp[i - 1]] == '(' {
			dp[i] = dp[i - 1] + 2 + dp[i - 2- dp[i - 1]]
		}
		if res < dp[i] {
			res = dp[i]
		}
	}
	return res
}