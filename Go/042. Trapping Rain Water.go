package main

func trap(height []int) int {
	leftMax := make([]int, len(height), len(height))
	rightMax := make([]int, len(height), len(height))
	for i, tmpMax := 0, 0; i < len(height); i++ {
		if tmpMax < height[i] {
			tmpMax = height[i]
		}
		leftMax[i] = tmpMax
	}
	for i, tmpMax := len(height) - 1, 0; i >= 0; i-- {
		if tmpMax < height[i] {
			tmpMax = height[i]
		}
		rightMax[i] = tmpMax
	}
	res := 0
	for i := 0; i < len(height); i++ {
		min := leftMax[i]
		if min > rightMax[i] {
			min = rightMax[i]
		}
		res += min - height[i]
	}
	return res
}