func longestPalindrome(s string) string {
	var dp [][]bool
	dp = make([][]bool, len(s), len(s))
	for i := 0; i < len(s); i++ {
		dp[i] = make([]bool, len(s), len(s))
		for j := 0; j < len(s); j++ {
			dp[i][j] = true
		}
	}
	start, end := 0, 0
	for j := 0; j < len(s); j++ {
		for i := j - 1; i >= 0; i-- {
			dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j]
			if dp[i][j] && end - start < j - i {
				start, end = i, j
			}
		}
	}
	return s[start : end + 1]
}