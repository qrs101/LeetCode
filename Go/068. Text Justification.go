package main

func fullJustify(words []string, maxWidth int) []string {
	res := make([]string, 0, 0)
	length, pureLength := 0, 0
	var i, j int
	for i, j = 0, 0; j < len(words); j++ {
		if length + len(words[j]) <= maxWidth {
			length = length + len(words[j]) + 1
			pureLength = pureLength + len(words[j])
		} else {
			if j == i + 1 {
				line := words[i]
				for t := 0; t < maxWidth - pureLength; t++ {
					line = line + " "
				}
				res = append(res, line)
			} else {
				space := (maxWidth - pureLength) / (j - i - 1)
				overSpace := (maxWidth - pureLength) % (j - i - 1)
				line := words[i]
				for k := i + 1; k < j; k++ {
					tmp := ""
					for t := 0; t < space; t++ {
						tmp = tmp + " "
					}
					if overSpace > 0 {
						tmp = tmp + " "
						overSpace--
					}
					line = line + tmp + words[k]
				}
				res = append(res, line)
			}
			i = j
			length = len(words[j]) + 1
			pureLength = len(words[j])
		}
	}
	line := words[i]
	for k := i + 1; k < j; k++ {
		line = line + " " + words[k]
	}
	for k, l := 0, maxWidth - len(line); k < l; k++ {
		line = line + " "
	}
	res = append(res, line)
	return res
}