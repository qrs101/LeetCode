func longestCommonPrefix(strs []string) string {
	if len(strs) == 0 {
		return ""
	}
	for i := 0; i < len(strs[0]); i++ {
		for k := 1; k < len(strs); k++ {
			if i >= len(strs[k]) || strs[k][i] != strs[0][i] {
				return strs[0][0 : i]
			}
		}
	}
	return strs[0]
}
