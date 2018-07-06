func min(a int, b int) int {
	if a < b {
		return a
	}
	return b
}

func maxArea(height []int) int {
	i, j := 0, len(height) - 1
	res := 0
	for i < j {
		tmp := min(height[i], height[j]) * (j - i)
		if res < tmp {
			res = tmp
		}
		if height[i] < height[j] {
			i++
		} else {
			j--;
		}
	}
	return res
}