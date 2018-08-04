package main

import "sort"

func permute(nums []int) [][]int {
	sort.Ints(nums)
	res := make([][]int, 0, 0)
	for true {
		tmp := make([]int, len(nums), len(nums))
		copy(tmp, nums)
		res = append(res, tmp)
		var i, j int
		for i = len(nums) - 2; i >= 0 && nums[i] > nums[i + 1]; i-- {}
		if i < 0 {
			break
		}
		for j = i + 1; j < len(nums) && nums[j] > nums[i]; j++ {}
		nums[i], nums[j - 1] = nums[j - 1], nums[i]
		for i, j = i + 1, len(nums) - 1; i < j; i, j = i + 1, j - 1 {
			nums[i], nums[j] = nums[j], nums[i]
		}
	}
	return res
}