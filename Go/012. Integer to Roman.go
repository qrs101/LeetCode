func intToRoman(num int) string {
	bit := [][]string {
		{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
		{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
		{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
		{"", "M", "MM", "MMM"},
	}
	res := ""
	for i, k := 1000, 3; k >= 0; k-- {
		res = res + bit[k][num / i]
		num = num % i
		i = i / 10
	}
	return res
}