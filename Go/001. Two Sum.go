package main

func twoSum(nums []int, target int) []int {
	N := len(nums)
	m := make(map[int]int)
	res := make([]int, 2, 2)
	for i := 0; i < N; i++ {
		if _, ok := m[nums[i]]; ok {
			res[0] = m[nums[i]]
			res[1] = i
			break
		}
		m[target - nums[i]] = i
	}
	return res
}