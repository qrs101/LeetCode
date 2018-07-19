func romanToInt(s string) int {
	bit := map[string]int {
		"I":1, "V":5, "X":10, "L":50, "C":100, "D":500, "M":1000,
	}
	res := bit[s[len(s) - 1 : len(s)]]
	for i := len(s) - 2; i >= 0; i-- {
		if bit[s[i : i + 1]] < bit[s[i + 1 : i + 2]] {
			res -= bit[s[i : i + 1]]
		} else {
			res += bit[s[i : i + 1]]
		}
	}
	return res
}