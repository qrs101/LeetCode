const INT_MAX = 2147483647
const INT_MIN = -2147483648

func myAtoi(str string) int {
	var i int
	for i = 0; i < len(str) && str[i] == ' '; i++ {}
	str = str[i : ]
	var symbol int64 = 1
	if len(str) > 0 && str[0] == '+' {
		str = str[1 :]
	} else if len(str) > 0 && str[0] == '-' {
		symbol = -1
		str = str[1 :]
	}
	for i = 0; i < len(str) && str[i] >= '0' && str[i] <= '9'; i++ {}
	str = str[0 : i]
	var res int64 = 0
	for i = 0; i < len(str); i++ {
		res *= 10
		res += int64(str[i] - '0')
		if symbol * res > INT_MAX {
			return INT_MAX
		}
		if symbol * res < INT_MIN {
			return INT_MIN
		}
	}
	return int(symbol * res)
}