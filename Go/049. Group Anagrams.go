package main

import	"strconv"

func groupAnagrams(strs []string) [][]string {
	res := make([][]string, 0)
	m := make(map[string][]string)
	for _, str := range strs {
		tmp := helper(str)
		if _, ok := m[tmp]; !ok {
			m[tmp] = make([]string, 0, 1)
		}
		m[tmp] = append(m[tmp], str)
	}
	for _, v := range m {
		res = append(res, v)
	}
	return res
}

func helper(str string) string {
	res := ""
	tmp := make([]int, 26, 26)
	for i := 0; i < 26; i++ {
		tmp[i] = 0
	}
	for i := 0; i < len(str); i++ {
		tmp[str[i] - 'a']++
	}
	for i := 0; i < 26; i++ {
		res += strconv.Itoa(tmp[i])
	}
	return res
}