package main

import "strconv"

func getPermutation(n int, k int) string {
	num := make([]int, n, n)
	for i := 0; i < n; i++ {
		num[i] = i + 1
	}
	for i := 2; i <= k; i++ {
		var a, b int
		for a = n - 2; a >= 0 && num[a] > num[a + 1]; a-- {}
		for b = a + 1; b < n && num[b] > num[a]; b++ {}
		b--
		num[a], num[b] = num[b], num[a]
		for a, b = a + 1, n - 1; a < b; a, b = a + 1, b - 1 {
			num[a], num[b] = num[b], num[a]
		}
	}
	res := ""
	for i := 0; i < n; i++ {
		res += strconv.Itoa(num[i])
	}
	return res
}