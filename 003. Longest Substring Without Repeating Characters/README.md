# Problem
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given `"abcabcbb"`, the answer is `"abc"`, which the length is 3.

Given `"bbbbb"`, the answer is `"b"`, with the length of 1.

Given `"pwwkew"`, the answer is `"wke"`, with the length of 3. Note that the answer must be a substring, `"pwke"` is a subsequence and not a substring.

# Solution
## My Solution
Use a sliding window. Define pointer `start` and `end` to denote the start and end of current substring. Initial `start = -1, end = 0, max_length = 0`. And use a hash table store `<character, its index>`. Every step `end++`, and check if the hash table have the key `s[end]`. If have, delete key befor `hash[s[end]]` from hash table, and update `start = hash[end], hash[end] = end, max_length = max(max_length, end - start)`

Time complexity: `O(2n) = O(n)`

Space complexity: `O(m)`, where `m` is the max length of substring.
## LeetCode's Solution
It don't need to delete element from hash table. Every step to update `start`, it could compare `start` with `hash[end]`, take the greater one.

Time complexity: `O(n)`

Complexity: `O(n)`