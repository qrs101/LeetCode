# Problem
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example
```
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
```

# Solution
## My Solution
Considering the carry, before the end of both link lists, add the two numbers and the carry.
```
num = l1->val + l2->val + carry;
carry = num / 10
```

Time complexity: `O(max(m, n))`.

Space complexity: `O(max(m, n))`.
`m,n` are length of the two lists respectively.

## LeetCode's Solution
Same as mine