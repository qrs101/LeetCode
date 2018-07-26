package main

import (
	"math"
	"sort"
)

func threeSumClosest(nums []int, target int) int {
	res, max := 0, math.MaxFloat64
	sort.Ints(nums)
	for k := 0; k < len(nums); {
		for i, j := k + 1, len(nums) - 1; i < j; {
			cur := nums[i] + nums[j] + nums[k]
			if cur == target {
				return target
			} else if cur < target {
				for i++; i < j && nums[i] == nums[i - 1]; i++ {}
			} else {
				for j--; i < j && nums[j] == nums[j + 1]; j-- {}
			}
			if tmp := math.Abs(float64(cur - target)); tmp < max {
				max = tmp
				res = cur
			}
		}
		for k++; k < len(nums) && nums[k] == nums[k - 1]; k++ {}
	}
	return res
}