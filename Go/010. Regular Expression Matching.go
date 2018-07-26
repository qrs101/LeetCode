package main

func isMatch(s string, p string) bool {
	M, N := len(s), len(p)
	dp := make([][]bool, N + 1, N + 1)
	for i := 0; i <= N; i++ {
		dp[i] = make([]bool, M + 1, M + 1)
	}
	s, p = "*" + s, "*" + p
	for i := 0; i <= N; i += 2 {
		if p[i] == '*' {
			dp[i][0] = true
		} else {
			break
		}
	}
	for i := 1; i <= N; i++ {
		for j := 1; j <= M; j++ {
			if (p[i] == s[j] || p[i] == '.') && dp[i - 1][j - 1] {
				dp[i][j] = true
			}
			if p[i] == '*' {
				if dp[i - 2][j] {
					dp[i][j] = true
				} else {
					for k := j; k > 0 && (s[k] == p[i - 1] || p[i - 1] == '.'); k-- {
						if dp[i - 2][k - 1] {
							dp[i][j] = true
							break
						}
					}
				}
			}
		}
	}
	return dp[N][M]
}