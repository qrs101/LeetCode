func maxProfit(prices []int) int {
	res := 0
	if len(prices) == 0 {
		return res
	}
	
	min := prices[0]
	max := prices[0]
	for i := 0; i < len(prices); i++ {
		if prices[i] > max {
			max = prices[i]
		} else if prices[i] < min {
			min = prices[i]
			max = prices[i]
		}
		if max - min > res {
			res = max - min
		}
	}
	return res
}

/*
func maxProfit(prices []int) int {
	res := 0
	if len(prices) == 0 {
		return res
	}
	min := prices[0]
	for i := 0; i < len(prices); i++ {
		if prices[i] < min {
			min = prices[i]
		}
		if res < prices[i] - min {
			res = prices[i] - min
		}
	}
	return res
}
*/