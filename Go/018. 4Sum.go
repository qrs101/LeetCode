package main

import "sort"

func fourSum(nums []int, target int) [][]int {
	res := make([][]int, 0)
	sort.Ints(nums)
	for k := 0; k < len(nums); {
		for l := k + 1; l < len(nums); {
			for i, j := l + 1, len(nums) - 1; i < j; {
				if nums[k] + nums[l] + nums[i] + nums[j] == target {
					res = append(res, []int{nums[k], nums[l], nums[i], nums[j]})
					for i++; i < j && nums[i] == nums[i - 1]; i++ {}
					for j--; i < j && nums[j] == nums[j + 1]; j-- {}
				} else if nums[k] + nums[l] + nums[i] + nums[j] < target {
					for i++; i < j && nums[i] == nums[i - 1]; i++ {}
				} else {
					for j--; i < j && nums[j] == nums[j + 1]; j-- {}
				}
			}
			for l++; l < len(nums) && nums[l] == nums[l - 1]; l++ {}
		}
		for k++; k < len(nums) && nums[k] == nums[k - 1]; k++ {}
	}
	return res
}