package main

import "strconv"

func addBinary(a string, b string) string {
	carry := 0
	res := ""
	for i, j := len(a) - 1, len(b) - 1; i >=0 || j >= 0; i, j = i - 1, j - 1 {
		num1, num2 := 0, 0
		if i >= 0 {
			num1 = int(a[i] - '0')
		}
		if j >= 0 {
			num2 = int(b[j] - '0')
		}
		carry = num1 + num2 + carry
		res = strconv.Itoa(carry & 1) + res
		carry = carry >> 1
	}
	if carry == 1 {
		res = "1" + res
	}
	return res
}