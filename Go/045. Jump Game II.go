package main

func jump(nums []int) int {
	loc, res := 0, 0
	for loc < len(nums) {
		if loc == len(nums) - 1 {
			return res
		} else if loc + nums[loc] >= len(nums) - 1 {
			return res + 1
		}
		nextLoc := loc
		for i, tmpMax := loc + 1, 0; i <= loc + nums[loc]; i++ {
			if tmpMax < i + nums[i] {
				nextLoc = i
				tmpMax = i + nums[i]
			}
		}
		loc, res = nextLoc, res + 1
	}
	return res
}