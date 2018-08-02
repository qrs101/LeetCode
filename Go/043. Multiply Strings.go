package main

import "strconv"

func multiply(num1 string, num2 string) string {
	size1, size2 := len(num1), len(num2)
	product := make([]int, size1 + size2)
	for i := size1 - 1; i >= 0; i-- {
		for j := size2 - 1; j >= 0; j-- {
			product[size1 + size2 - i - j - 2] += int(num1[i] - '0') * int(num2[j] - '0')
		}
	}
	carry, res := 0, ""
	for i := 0; i < size1 + size2; i++ {
		carry = product[i] + carry
		res = strconv.Itoa(carry % 10) + res
		carry = carry / 10
	}
	for carry = 0; carry < len(res) - 1 && res[carry] == '0'; carry++ {}
	return res[carry :]
}