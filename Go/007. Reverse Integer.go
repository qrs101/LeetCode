package main

func reverse(x int) int {
	const INT_MAX int64 = 2147483647
	const INT_MIN int64 = -2147483648
	var res int64 = 0
	var symbol int64 = 1
	if x < 0 {
		symbol = -1
		x = -x
	}
	for x != 0 {
		r := x % 10
		res *= 10
		res += int64(r)
		x /= 10
	}
	if symbol * res > INT_MAX || symbol * res < INT_MIN {
		return 0
	}
	return int(symbol * res)
}