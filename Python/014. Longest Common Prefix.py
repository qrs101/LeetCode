class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        ans = ""
        n = len(strs)
        if n == 0:
            return ans
        i = 0
        tag = True
        while tag:
            if i < len(strs[0]):
                c = strs[0][i]
            else:
                break
            for j in range(1, n):
                if i < len(strs[j]) and c == strs[j][i]:
                    pass
                else:
                    tag = False
            if tag:
                ans = ans + c
            i += 1
        return ans
