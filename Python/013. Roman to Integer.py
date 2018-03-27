class Solution:
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        D = {'#':0, 'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
        n = len(s)
        ans = 0
        s = s + '#'
        for i in range(n):
            if D[s[i]] < D[s[i + 1]]:
                ans = ans - D[s[i]]
            else:
                ans = ans + D[s[i]]
        return ans

so = Solution()
ans = so.romanToInt('')
#print(ans)