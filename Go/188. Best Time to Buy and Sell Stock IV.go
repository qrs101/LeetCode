func maxProfit(k int, prices []int) int {
	if len(prices) == 0 {
		return 0
	}
	if k >= len(prices) {
		res := 0
		for i := 1; i < len(prices); i++ {
			if prices[i] - prices[i - 1] > 0 {
				res += prices[i] - prices[i - 1]
			}
		}
		return res
	}
	var dp [][]int
	dp = make([][]int, k + 1, k + 1)
	for i := 0; i <= k; i++ {
		dp[i] = make([]int, len(prices), len(prices))
	}
	for i := 1; i <= k; i++ {
		max := dp[i - 1][0] - prices[0]
		for j := 1; j < len(prices); j++ {
			dp[i][j] = dp[i][j - 1]
			if max < dp[i - 1][j] - prices[j] {
				max = dp[i - 1][j] - prices[j]
			}
			if dp[i][j] < max + prices[j] {
				dp[i][j] = max + prices[j]
			}
		}
	}
	return dp[k][len(prices) - 1]
}