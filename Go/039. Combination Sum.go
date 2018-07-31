package main

import "sort"

func combinationSum(candidates []int, target int) [][]int {
	sort.Ints(candidates)
	return findSum(candidates, target)
}

func findSum(candidates []int, target int) [][]int {
	res := make([][]int, 0, 0)
	if len(candidates) == 0 || target < candidates[0] {
		return res
	}
	if candidates[0] == target {
		tmp := []int{target}
		res = append(res, tmp)
		return res
	}
	tmp1 := findSum(candidates[1 :], target)
	tmp2 := findSum(candidates, target - candidates[0])
	for i := 0; i < len(tmp2); i++ {
		tmp2[i] = append(tmp2[i], candidates[0])
	}
	res = append(res, tmp1...)
	res = append(res, tmp2...)
	return res
}