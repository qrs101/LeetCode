# Problem
There are two sorted arrays **nums1** and **nums2** of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
```
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
```

Example 2:
```
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
```

# Solution
## My Solution
No answer is made.

## LeetCode's Solution
Find the small length array `A` and its length is `m`, the other array and length is `B` and `n`. partition `A` and `B` into two parts respectively. if 
```
left_A.length + left_B.length == right_A.length + right_B.length
{left_A, left_B} <= {right_A, right_B}
```
then we can get the median. define `s = (m+n)/2+1` and `i`, `j` is the partition positon of `A` and `B`, where `i + j = s`. In the case of the above condition, binary search array `A`, and the anwser can be found.

Time complexity: `O(min(m, n))`

Complexity: `O(1)`