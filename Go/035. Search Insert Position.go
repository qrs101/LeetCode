package main

func searchInsert(nums []int, target int) int {
	i, j := 0, len(nums) - 1
	for i <= j {
		m := (i + j) / 2
		if nums[m] == target {
			return m
		} else if nums[m] < target {
			i = m + 1
		} else {
			j = m - 1
		}
	}
	if i == len(nums) || nums[i] > target {
		return i
	} else {
		return i + 1
	}
}