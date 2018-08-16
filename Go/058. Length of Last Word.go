package main

func lengthOfLastWord(s string) int {
	var i, j int
	for j = len(s) - 1; j >= 0 && s[j] == ' '; j-- {}
	for i = j; i >= 0 && s[i] != ' '; i-- {}
	return j - i
}