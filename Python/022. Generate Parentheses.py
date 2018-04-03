class Solution:
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        ans = []
        ans.append([""])
        for m in range(1, n + 1):
            l = []
            for k in range(1, m + 1):
                for i in ans[k - 1]:
                    for j in ans[m - k]:
                        l.append('(' + i + ')' + j)
            ans.append(l)
        return ans[n]

so = Solution()
ans = so.generateParenthesis(3)
print(ans)