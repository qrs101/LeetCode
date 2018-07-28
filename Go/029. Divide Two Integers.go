package main

import "math"

const (
	INT32_MIN int = -2147483648
	INT32_MAX int = 2147483647
)

func divide(dividend int, divisor int) int {
	if dividend == INT32_MIN && divisor == -1 {
		return INT32_MAX
	}
	res, symbol := 0, 1
	if dividend > 0 && divisor < 0 || dividend < 0 && divisor > 0 {
		symbol = -1
	}
	a, b := int64(math.Abs(float64(dividend))), int64(math.Abs(float64(divisor)))
	for a >= b {
		r , tmp := 1, b
		for a > (tmp << 1) {
			r <<= 1
			tmp <<= 1
		}
		a = a - tmp
		res = res + r
	}
	return symbol * res
}