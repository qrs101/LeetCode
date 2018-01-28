# Problem
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:
```
Input: "babad"

Output: "bab"
```
Note: "aba" is also a valid answer.
Example:
```
Input: "cbbd"

Output: "bb"
```

# Solution
## My Solution
Use a dp algorithm. Define 2-d bool array `a`, where `a[i,j] == true` means the substring `s[i to j]` is a palindromic substring.

## LeetCode's Solution
There are 5 solutions provided by LeetCode, including 
1. Longest Common Substring(O(n<sup>2</sup>), O(n<sup>2</sup>))
2. Brute Force(O(n<sup>3</sup>), O(1))
3. Dynamic Programming(used by me, O(n<sup>2</sup>), O(n<sup>2</sup>))
4. Expand Around Center(O(n<sup>2</sup>), O(1))
5. Manacher's Algorithm(a non-trivial algorithm with time complexity O(n) and space complexity O(1))

See [here](https://leetcode.com/problems/longest-palindromic-substring/solution/)