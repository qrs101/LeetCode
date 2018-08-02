package main

import "sort"

func combinationSum2(candidates []int, target int) [][]int {
	sort.Ints(candidates)
	return findSum(candidates, target)
}

func findSum(candidates []int, target int) [][]int {
	res := make([][]int, 0, 0)
	if len(candidates) == 0 || target < candidates[0] {
		return res
	}
	loc := 1
	for ; loc < len(candidates) && candidates[loc] == candidates[loc - 1]; loc++ {}
	curCandidates, leftCandidates := make([]int, 0), candidates[loc :]
	for i, num := 0, 0; i <= loc; i++ {
		if target - num == 0 {
			res = append(res, curCandidates)
			break
		} else if target - num > 0 {
			tmp := findSum(leftCandidates, target - num)
			for j := 0; j < len(tmp); j++ {
				tmp[j] = append(tmp[j], curCandidates...)
			}
			res = append(res, tmp...)
		} else {
			break
		}
		num += candidates[0]
		curCandidates = append(curCandidates, candidates[0])
	}
	return res
}