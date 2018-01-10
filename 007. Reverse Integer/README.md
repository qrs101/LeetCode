# Problem
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:
```
Input: 123
Output:  321
```
Example 2:
```
Input: -123
Output: -321
```
Example 3:
```
Input: 120
Output: 21
```
Note:
Assume we are dealing with an environment which could only hold integers within the 32-bit signed integer range. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

# Solution
## My Solution
the range of input `x` is [-2<sup>31</sup>, 2<sup>31</sup>), i.e. `-2147483648 <= x <= 2147483647`. Consequencely, if `x == -2147483648`, return 0, else map `x` to a positive integer. Store all digits in a stack one by one, and judge whether the reverse number is overflowed. At last, restore the reverse number one by one.

## LeetCode's Solution
No answer
