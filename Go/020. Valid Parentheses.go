package main

func isValid(s string) bool {
	Stack := make([]uint8, len(s), len(s))
	top := -1
	m := map[uint8]uint8 {
		'(' : ')', '[' : ']', '{' : '}',
	}
	for i := 0; i < len(s); i++ {
		if s[i] == '(' || s[i] == '[' || s[i] == '{' {
			top++
			Stack[top] = s[i]
		} else {
			if top == -1 || s[i] != m[Stack[top]] {
				return false
			}
			top--
		}
	}
	return top == -1
}