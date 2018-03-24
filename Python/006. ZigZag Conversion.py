class Solution:
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1:
            return s
        L = list()
        for i in range(numRows):
            L.append([])
        j = 0
        tag = True
        for i in range(len(s)):
            if tag:
                L[j].append(s[i])
                j += 1
                if j == numRows - 1:
                    tag = False
            else:
                L[j].append(s[i])
                j -= 1
                if j == 0:
                    tag = True
        ans = ""
        for i in L:
            ans = ans + "".join(i)
        return ans

s = Solution()
ans = s.convert("PAYPALISHIRING", 3)
print(ans)