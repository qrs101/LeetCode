package main

func myPow(x float64, n int) float64 {
	if x == 0 {
		return 0
	}
	if n == 0 {
		return 1
	}
	if n < 0 {
		x = 1 / x
		n = -n
	}
	var res float64
	if n & 1 == 1 {
		res = x
	} else {
		res = 1
	}
	res = res * myPow(x * x, n >> 1)
	return res
}