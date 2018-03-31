class Solution:
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        d2l = ['', '', 'abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz']
        ans = []
        if len(digits) == 0:
            return ans
        s = d2l[int(digits[0])]
        tmp = self.letterCombinations(digits[1:])
        if len(tmp) == 0:
            return list(s)
        elif s == '':
            return tmp
        else:
            for i in s:
                for j in tmp:
                    ans.append(i + j)
        return ans