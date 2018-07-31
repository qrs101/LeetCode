package main

import "strconv"

func countAndSay(n int) string {
	res := make(map[int]string)
	res[1] = "1"
	for i := 2; i <= n; i++ {
		str := res[i - 1]
		res[i] = ""
		n, j := 1, 1
		for ; j < len(str); j++ {
			if str[j] == str[j - 1] {
				n++
			} else {
				res[i] += strconv.Itoa(n) + str[j - 1 : j]
				n = 1
			}
		}
		res[i] += strconv.Itoa(n) + str[j - 1 : j]
	}
	return res[n]
}