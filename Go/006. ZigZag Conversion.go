package main

func convert(s string, numRows int) string {
	if numRows == 1{
		return s
	}
	var res string
	N := len(s)
	m := (N - 1) / (numRows - 1) + 1
	for i := 0; i < numRows; i++ {
		for j := 0; j <= m; j += 2 {
			index := j * (numRows - 1)
			if i == 0 || i == numRows - 1 {
				if index + i < N {
					res = res + s[index + i : index + i + 1]
				}
			} else {
				if index - i >= 0 && index - i < N {
					res = res + s[index - i : index - i + 1]
				}
				if index + i >= 0 && index + i < N {
					res = res + s[index + i : index + i + 1]
				}
			}
		}
	}
	return res
}

/*
func convert(s string, numRows int) string {
	if numRows == 1{
		return s
	}
	var res string
	tmp := make([]string, numRows)
	for i, n, tag := 0, 0, true; i < len(s); i++ {
		tmp[n] = tmp[n] + s[i : i + 1]
		if tag {
			n++
			if n == numRows - 1 {
				tag = false
			}
		} else {
			n--
			if n == 0 {
				tag = true
			}
		}
	}
	for i := 0; i < numRows; i++ {
		res += tmp[i]
	}
	return res
}
*/