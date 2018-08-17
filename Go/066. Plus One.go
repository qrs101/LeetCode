package main

func plusOne(digits []int) []int {
	carry := 1
	for i := len(digits) - 1; i >= 0; i-- {
		carry = carry + digits[i]
		digits[i] = carry % 10
		carry = carry / 10
		if carry == 0 {
			break
		}
	}
	if carry == 0 {
		return digits
	} else {
		return append([]int{carry}, digits...)
	}
}