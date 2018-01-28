# Problem
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.
```
For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
```

# Solution
The idea is to fix the first nubmer `a[i]`, and find two nubmers which add up equals `-a[i]`. My solution is time out, as shown in main1.cpp. another method is sorting the array first, and skip the duplicate number, as shown in main2.cpp.