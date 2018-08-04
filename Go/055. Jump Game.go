package main

func canJump(nums []int) bool {
	loc := 0
	for loc < len(nums) {
		if loc + nums[loc] >= len(nums) - 1 {
			return true
		}
		if nums[loc] == 0 {
			return false
		}
		nextLoc := loc
		for i, tmpMax := loc + 1, 0; i <= loc + nums[loc]; i++ {
			if tmpMax < i + nums[i] {
				nextLoc = i
				tmpMax = i + nums[i]
			}
		}
		loc = nextLoc
	}
	return true
}