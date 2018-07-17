class Solution:
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        m = len(s)
        n = len(p)
        s = '#' + s
        p = '#' + p
        dp = []
        for i in range(n + 1):
            dp.append([False] * (m + 1))
        dp[0][0] = True
        i = 2
        while i <= n and p[i] == '*':
            dp[i][0] = True
            i = i + 2
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if (p[i] == '.' or p[i] == s[j]) and dp[i - 1][j - 1]:
                    dp[i][j] = True
                if p[i] == '*':
                    if dp[i - 2][j]:
                        dp[i][j] = True
                    else:
                        t = j
                        while t > 0 and (p[i - 1] == s[t] or p[i - 1] == '.'):
                            if dp[i - 2][t - 1]:
                                dp[i][j] = True
                                break
                            t -= 1
                #print(i, ' ', j, ' ', dp[i][j])
        return dp[n][m]

so = Solution()
ans = so.isMatch('aab', 'c*a*b')
print(ans)