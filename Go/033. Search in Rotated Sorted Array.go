package main

func search(nums []int, target int) int {
	i, j := 0, len(nums) - 1
	for i <= j {
		m := (i + j ) / 2
		if nums[m] == target {
			return m
		}
		if nums[i] > nums[m] && (target >= nums[i] || target < nums[m]) {
			j = m - 1
		} else if nums[i] < nums[m] && target >= nums[i] && target < nums[m] {
			j = m - 1
		} else {
			i = m + 1
		}
	}
	return -1
}