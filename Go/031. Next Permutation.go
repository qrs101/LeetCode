package main

func nextPermutation(nums []int)  {
	i, j := 0, 0
	for i = len(nums) - 2; i >= 0 && nums[i] >= nums[i + 1]; i-- {}
	if i == -1 {
		reverse_order(nums, 0, len(nums) - 1)
		return
	}
	for j = i + 1; j < len(nums) && nums[j] > nums[i]; j++ {}
	nums[i], nums[j - 1] = nums[j - 1], nums[i]
	reverse_order(nums, i + 1, len(nums) - 1)
}

func reverse_order(nums []int, i int, j int) {
	for i < j {
		nums[i], nums[j] = nums[j], nums[i]
		i++
		j--
	}
}