package main

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	N1 := len(nums1)
	N2 := len(nums2)
	if N1 < N2 {
		N1, N2 = N2, N1
		nums1, nums2 = nums2, nums1
	}

	start, end := 0, N2 - 1
	var (
		j int = (start + end + 1) / 2
		i int = (N1 + N2) / 2 - j
	)
	for start <= end {
		if i != 0 && j != N2 && nums1[i - 1] > nums2[j] {
			start = j + 1
		} else if j != 0 && i != N1 && nums2[j - 1] > nums1[i] {
			end = j - 1
		} else {
			break
		}
		j = (start + end + 1) / 2
		i = (N1 + N2) / 2 - j
	}

	var Min float64
	if j == N2 {
		Min = float64(nums1[i])
	} else if i == N1 {
		Min = float64(nums2[j])
	} else if nums1[i] < nums2[j] {
		Min = float64(nums1[i])
	} else {
		Min = float64(nums2[j])
	}
	if (N1 + N2) & 1 == 1 {
		return Min
	} else {
		var Max float64
		if j == 0 {
			Max = float64(nums1[i - 1])
		} else if i == 0 {
			Max = float64(nums2[j - 1])
		} else if nums1[i - 1] > nums2[j - 1] {
			Max = float64(nums1[i - 1])
		} else {
			Max = float64(nums2[j - 1])
		}
		return (Max + Min) / 2
	}
}