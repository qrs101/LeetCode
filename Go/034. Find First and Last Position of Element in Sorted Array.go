package main

func searchRange(nums []int, target int) []int {
	res := []int{-1, -1}
	if len(nums) == 0 {
		return res
	}
	i, j := 0, len(nums) - 1
	if nums[i] == target {
		res[0] = i
	} else {
		for j - i > 1 {
			m := (i + j) / 2
			if nums[m] >= target {
				j = m
			} else {
				i = m
			}
		}
		if nums[j] == target && nums[i] != target {
			res[0] = j
		}
	}
	i, j = 0, len(nums) - 1
	if nums[j] == target {
		res[1] = j
	} else {
		for j - i > 1 {
			m := (i + j ) / 2
			if nums[m] > target {
				j = m
			} else {
				i = m
			}
		}
		if nums[i] == target && nums[j] != target {
			res[1] = i
		}
	}
	return res
}