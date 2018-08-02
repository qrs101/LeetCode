package main

func isMatch(s string, p string) bool {
	lenP, lenS := len(p), len(s)
	dp := make([][]bool, lenP + 1, lenP + 1)
	for i := 0; i <= lenP; i++ {
		dp[i] = make([]bool, lenS + 1, lenS + 1)
	}
	s, p, dp[0][0] = "#" + s, "#" + p, true
	for i := 1; i <= lenP && p[i] == '*' ; i++ {
		dp[i][0] = true
	}
	for i := 1; i <= lenP; i++ {
		for j := 1; j <= lenS; j++ {
			if (p[i] == '?' || p[i] == s[j]) && dp[i - 1][j - 1] {
				dp[i][j] = true
			} else if p[i] == '*' {
				for k := j; k >= 0; k-- {
					if dp[i - 1][k] {
						dp[i][j] = true
						break
					}
				}
			}
		}
	}
	return dp[lenP][lenS]
}