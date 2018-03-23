import numpy as np

class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        n = len(s)
        dp = np.zeros(shape=[n, n])
        loc, length = 0, 0
        for l in range(n):
            for i in range(n):
                if i >= n - l:
                    break
                if (l <= 2 or dp[l - 2, i + 1] == 1) and s[i] == s[i + l]:
                    dp[l, i] = 1
                    loc = i
                    length = l

        return s[loc : loc + length + 1]