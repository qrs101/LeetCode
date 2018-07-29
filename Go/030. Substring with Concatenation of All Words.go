package main

func findSubstring(s string, words []string) []int {
	res, str2num := make([]int, 0), make(map[string]int)
	if len(s) == 0 || len(words) == 0 || len(words[0]) == 0 {
		return res
	}
	for _, str := range words {
		if _, ok := str2num[str]; !ok {
			str2num[str] = 1
		} else {
			str2num[str] += 1
		}
	}
	for i := 0; i <= len(s) - len(words) * len(words[0]); i++ {
		seen, tag := make(map[string]int), true
		for k, v := range str2num {
			seen[k] = v
		}
		for j, n := 0, len(words[0]); tag && j < len(words); j++ {
			str := s[i + j * n : i + (j + 1) * n]
			if val, ok := seen[str]; ok && val > 0 {
				seen[str]--
			} else {
				tag = false
			}
		}
		if tag {
			res = append(res, i)
		}
	}
	return res
}