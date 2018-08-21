package main

func mySqrt(x int) int {
	if x == 0 {
		return 0
	}
	i, j := 1, x / 2 + 1
	for i < j - 1 {
		m := (i + j) / 2
		tmp := m * m
		if tmp == x {
			return m
		} else if tmp < x {
			i = m
		} else {
			j = m
		}
	}
	return i
}