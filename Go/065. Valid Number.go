package main

func isInteger(s string) bool {
	if len(s) == 0 {
		return false
	}
	if s[0] == '+' || s[0] == '-' {
		s = s[1:]
	}
	if len(s) == 0 {
		return false
	}
	for i := 0; i < len(s); i++ {
		if s[i] < '0' || s[i] > '9' {
			return false
		}
	}
	return true
}

func isFloat(s string) bool {
	if len(s) == 0 {
		return false
	}
	if s[0] == '+' || s[0] == '-' {
		s = s[1:]
	}
	if len(s) == 0 || s == "." {
		return false
	}
	haveDot := false
	for i := 0; i < len(s); i++ {
		if s[i] == '.' {
			if !haveDot {
				haveDot = true
			} else {
				return false
			}
		} else if s[i] < '0' || s[i] > '9' {
			return false
		}
	}
	return true
}

func isNumber(s string) bool {
	var i int = 0
	for i = 0; i < len(s) && s[i] == ' '; i++ {}
	s = s[i:]
	for i = len(s) - 1; i >= 0 && s[i] == ' '; i-- {}
	s = s[:i + 1]
	if len(s) == 0 {
		return false
	}
	haveE := false
	str1, str2 := "", ""
	for i := 0; i < len(s); i++ {
		if s[i] == 'e' || s[i] == 'E' {
			str1 = s[: i]
			str2 = s[i + 1:]
			haveE = true
			break
		}
	}
	if haveE {
		return isFloat(str1) && isInteger(str2)
	} else {
		return isFloat(s)
	}
}