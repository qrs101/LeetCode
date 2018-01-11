# Problem
Determine whether an integer is a palindrome. Do this without extra space.

# Solution
## My Solution
If the input `x < 0`, it is not a palindrome.  Reverse the input `x`. If the reverse number equals to `x`, then the number is a palindrome. Code is shown in main1.cpp

Time complexity: `O(n)`, `n` is the length of `x`

Space complexity: `O(1)`

## LeetCode's Solution
If the input `x < 0` or `x` is end of `0` but `x != 0`, it is not a palindrome. Reverse half of `x`, if the reverse number equals to the rest, then `x` is a palindrome. Code is shown in main2.cpp

Time complexity: `O(n)`

Complexity: `O(1)`