import "sort"

func threeSum(nums []int) [][]int {
	res := make([][]int, 0, 0)
	sort.Ints(nums)
	for k := 0; k < len(nums); {
		if nums[k] > 0 {
			break
		}
		for i, j := k + 1, len(nums) - 1; i < j; {
			if nums[i] + nums[j] == -nums[k] {
				tmp := []int{nums[k], nums[i], nums[j]}
				res = append(res, tmp)
				for i++; i < j && nums[i] == nums[i - 1]; i++ {}
				for j--; i < j && nums[j] == nums[j + 1]; j-- {}
			} else if nums[i] + nums[j] < -nums[k] {
				for i++; i < j && nums[i] == nums[i - 1]; i++ {}
			} else {
				for j--; i < j && nums[j] == nums[j + 1]; j-- {}
			}
		}
		for k++; k < len(nums) && nums[k] == nums[k - 1]; k++ {}
	}
	return res
}