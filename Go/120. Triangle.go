package main

func minimumTotal(triangle [][]int) int {
	if len(triangle) == 0 {
		return 0
	}
	var res []int = make([]int, len(triangle), len(triangle))
	copy(res, triangle[len(triangle) - 1])
	for n := len(triangle) - 1; n > 0; n-- {
		for j := 0; j < n; j++ {
			if res[j] < res[j + 1] {
				res[j] = res[j] + triangle[n - 1][j]
			} else {
				res[j] = res[j + 1] + triangle[n - 1][j]
			}
		}
	}
	return res[0]
}