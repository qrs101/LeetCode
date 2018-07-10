func lengthOfLongestSubstring(s string) int {
	m := make(map[string]int)
	res := 0
	for start, end := 0, 0; end < len(s); end++ {
		ch := s[end : end + 1]
		if _, ok := m[ch]; !ok {
			m[ch] = end
		} else {
			if start <= m[ch] {
				start = m[ch] + 1
			}
			m[ch] = end
		}
		if res < end - start + 1 {
			res = end - start + 1
		}
	}
	return res
}