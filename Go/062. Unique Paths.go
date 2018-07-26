package main

func uniquePaths(m int, n int) int {
	var dp [][]int
	dp = make([][]int, m + 1)
	for i := 0; i <= m; i++ {
		dp[i] = make([]int, n + 1)
	}
	dp[0][1] = 1
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
		}
	}

	return dp[m][n]
}