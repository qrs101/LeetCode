# Problem
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
```
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
```
# Solution
## Dynamic Programming
`text` and `pattern` represent the string and regular expression respectively. `dp[i,j] == true` denotes `pattern[i:]` and `text[j:]` can match. Code is shown in main1.cpp.

## Recurssion
Judge the relationship between `text[0]` and `pattern[0]`, return `isMatch(text[1:], pattern[1:]`. Code is shown in main2.cpp.
