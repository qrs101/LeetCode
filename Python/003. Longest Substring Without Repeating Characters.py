class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        ans = 0
        d = dict()
        i = 0
        for j in range(len(s)):
            if s[j] in d and d[s[j]] >= i:
                i = d[s[j]] + 1
            d[s[j]] = j
            if ans < j - i + 1:
                ans = j - i + 1
        return ans