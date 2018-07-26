package main

func generateParenthesis(n int) []string {
	res := make([]string, 0, 0)
	return helper(res, "", n, 0)
}

func helper(res []string, str string, left int, right int) []string{
	if left == 0 && right == 0 {
		res = append(res, str)
		return res
	}
	if right > 0 {
		res = helper(res, str + ")", left, right - 1)
	}
	if left > 0 {
		res = helper(res, str + "(", left - 1, right + 1)
	}
	return res
}